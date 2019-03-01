int UD = 0;
int LR = 0;
/* Arduino Micro output pins*/
int DWN = 13;
int UP = 12;
int LEFT = 11;
int RT = 10;
/* Arduino Micro Input Pins */
int IUP=A0;
int ILR=A1;

int MID = 10; // 10 mid point delta arduino, use 4 for attiny
int LRMID = 0;
int UPMID = 0;

int Button = 7;
int val = 0;
#include <Servo.h>

Servo servo1;
Servo servo2;
int joyX = 0;
int joyY = 1;
  
int servoVal;
  


void setup(){
  
  pinMode(DWN, OUTPUT);
  pinMode(UP, OUTPUT);  
  pinMode(LEFT, OUTPUT); 
  pinMode(RT, OUTPUT);
  pinMode(Button, INPUT);
   
  digitalWrite(DWN, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RT, HIGH);
  
  //calabrate center
  LRMID = analogRead(ILR);
  UPMID = analogRead(IUP);

  servo1.attach(3);
  servo2.attach(5);
}

void loop(){

  val=digitalRead(Button);
  if(val=HIGH){
    digitalWrite(DWN, LOW);
    digitalWrite(UP, LOW);
    digitalWrite(LEFT, LOW);
    digitalWrite(RT, LOW);
  }
  
  UD = analogRead(joyX);
  LR = analogRead(joyY);
  // UP-DOWN
  if(UD < UPMID - MID){
   digitalWrite(DWN, LOW);
  }
  else{
   digitalWrite(DWN, HIGH);
  }
  
  if(UD > UPMID + MID){
   digitalWrite(UP, LOW);
  }
  else{
   digitalWrite(UP, HIGH);
  }
  // LEFT-RIGHT
  if(LR < LRMID - MID){
   digitalWrite(LEFT, LOW);
  }
  else{
   digitalWrite(LEFT, HIGH);
  }
  
  if(LR > LRMID + MID){
   digitalWrite(RT, LOW);
  }
  else{
   digitalWrite(RT, HIGH);
  }

  servoVal = analogRead(joyX);
  servoVal = map(servoVal, 0, 1023, 0, 180);
  servo1.write(servoVal);
 
  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 1023, 70, 180);
  servo2.write(servoVal);
  delay(15);  
 
  delay(400);

  
  if(val=LOW){
    digitalWrite(DWN, HIGH);
    digitalWrite(UP, HIGH);
    digitalWrite(LEFT, HIGH);
    digitalWrite(RT, HIGH);
  }


}
