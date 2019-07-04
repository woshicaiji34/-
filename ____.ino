void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
int incoming = 0;
void loop()
{
  if ( Serial.available() )
  {
      incoming = Serial.read();
      switch( incoming )
      {
        case 'f': forward();  digitalWrite(12,LOW);  digitalWrite(13,LOW);    break;
        case 'b': backward(); digitalWrite(12,LOW);  digitalWrite(13,LOW);    break;
        case 'l': left();
        while ( !Serial.available() )
        {
          digitalWrite(13,HIGH); digitalWrite(12,LOW);delay(500);
          digitalWrite(13,LOW); digitalWrite(12,LOW);delay(500);    
        }
        break;
        case 'r': right();
        while ( !Serial.available() )
        {
          digitalWrite(12,HIGH); digitalWrite(13,LOW);delay(500);
          digitalWrite(13,LOW); digitalWrite(12,LOW);delay(500);
        }
        break;
        case 's': stop(); 
        digitalWrite(12,LOW);  digitalWrite(13,LOW);    break;
        default: break;           
    }    
  } 
}

void forward(){
  digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
}
void backward()
{
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
}

void left()
{
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    
}

void right()
{
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    
}
void stop()
{
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
}
