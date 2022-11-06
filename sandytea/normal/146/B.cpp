//program 146B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Mask(int x)
{
  int Len=0,Data[10];
  while(x){Data[Len++]=x%10;x/=10;}
  int Sum=0;
  while(Len--)
    if(Data[Len]==4||Data[Len]==7)
      Sum=Sum*10+Data[Len];
  return Sum;
}

int main()
{
  int A,B;cin>>A>>B;
  while(Mask(++A)!=B);
  cout<<A<<endl;
  return 0;
}