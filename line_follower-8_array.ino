int s1=A0, s2=A1, s3=A2, s4=A3, s5=A4, s6=A5, s7=8,s8=9;
int mR1=3, mR2=5, mL1=6, mL2=11;
int sensor[8];
int x=0,y=0,z=0;
int p=0;
unsigned long number;
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
void setup()
{
  Serial.begin(9600);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);
  pinMode(s8, INPUT);
}
void numeric_convertion()
{
  number = digitalRead(s1);
  sensor[0] = digitalRead(s1);
  sensor[1] = digitalRead(s2);
  sensor[2] = digitalRead(s3);
  sensor[3] = digitalRead(s4);
  sensor[4] = digitalRead(s5);
  sensor[5] = digitalRead(s6);
  sensor[6] = digitalRead(s7);
  sensor[7] = digitalRead(s8);
  
  for (byte i = 1; i < 8; i++)
  {
    number = number * 10 + sensor[i];
  }
  Serial.println(number);
}
void loop()
{
  numeric_convertion();

  //left
  if(number==1111111)
  {
    left();
    x=1;
    y=0;
    z=0;
  }
  else if(number==1111)
  {
    left();
    x=1;
    y=0;
    z=0;
  }
  else if(number==111)
  {
    left6();
    x=1;
    y=0;
    z=0;
  }
  else if(number==111111)
  {
    left6();
    x=1;
    y=0;
    z=0;
  }
  else if(number==11111)
  {
    left5();
    x=1;
    y=0;
    z=0;
  }
  else if(number==10011111)
  {
    left4();
    x=1;
    y=0;
    z=0;
  }
  else if(number==10001111)
  {
    left3();
    x=1;
    y=0;
    z=0;
  }
  else if(number==11001111)
  {
    left2();
    x=1;
    y=0;
    z=0;
  }
  else if(number==11000111)
  {
    left1();
    x=1;
    y=0;
    z=0;
  }



  //forward
  else if(number==11100111)
  {
    fwd();
    x=0;
    y=1;
    z=0;
  }



  //right
  else if(number==11100011)
  {
    right1();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11110011)
  {
    right2();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11110001)
  {
    right3();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11111001)
  {
    right4();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11111000)
  {
    right5();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11111100)
  {
    right6();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11100000)
  {
    right();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11110000)
  {
    right();
    x=0;
    y=0;
    z=1;
  }
  else if(number==11111110)
  {
    right();
    x=0;
    y=0;
    z=1;
  }
  else if(x==1)
  {
    left();
  }
  else if(y==1)
  {
    fwd();
  }
  else if(z==1)
  {
    right();
  }
  
}
void fwd()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}

//left
void left()
{
  motor1.setSpeed(0);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}
void left1()
{
  motor1.setSpeed(180+p);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}
void left2()
{
  motor1.setSpeed(150+p);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}
void left3()
{
  motor1.setSpeed(120+p);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}
void left4()
{
  motor1.setSpeed(90+p);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}
void left5()
{
  motor1.setSpeed(60+p);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}
void left6()
{
  motor1.setSpeed(130);
  motor1.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
}


//right
void right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(0);
  motor3.run(FORWARD); 
}
void right1()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(180+p);
  motor3.run(FORWARD);
}
void right2()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(150+p);
  motor3.run(FORWARD);
}
void right3()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(120+p);
  motor3.run(FORWARD);
}
void right4()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(90+p);
  motor3.run(FORWARD);
}
void right5()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(60+p);
  motor3.run(FORWARD);
}
void right6()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor3.setSpeed(30);
  motor3.run(FORWARD);
}
