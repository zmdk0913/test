#include <Servo.h>

int LED = 8;
int motor = 2;
#define trig 12
#define echo 13
Servo myservo;



void setup()

{
  Serial.begin(9600);
  myservo.attach(motor); 
  pinMode(LED, OUTPUT);
  pinMode(trig, OUTPUT); //trig 선언
  pinMode(echo, INPUT);  //echo 선언
}

 

void loop()

{
  long duration, distance; // 거리 측정 변수
  // trig핀에 10us 동안 펄스 출력
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH); 
  Serial.println(duration); // 거리 출력

  if(duration < 300) // 초음파 센서와 손의 거리가 가까우면
  {         

   myservo.write(90); // 서보모터를 이용해서 손소독제 분사
   digitalWrite(LED, HIGH); // 작동 확인용 LED ON
   delay(3000); // 3초 딜레이
   myservo.write(0); // 서보모터를 원래의 각도로 되돌림
   digitalWrite(LED, LOW); // 작동 확인용 LED OFF

  }

  else if(duration >= 300) // 초음파 센서와 손의 거리가 멀면
  {            
      myservo.write(0); // 원래의 각도 유지
      delay(2);
  }
  delay(200);
  }
