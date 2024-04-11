//program 317-D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool Flag=(c=='-');
  if(Flag)
    c=getchar();
  int X=0;
  while(c>='0'&&c<='9')
    {
      X=X*10+c-48;
      c=getchar();
    }
  return Flag?-X:X;
}

void Output(int X)
{
  if(X<0)
    {
      putchar('-');
      X=-X;
    }
  int Len=0,Data[10];
  while(X)
    {
      Data[Len++]=X%10;
      X/=10;
    }
  if(!Len)
    Data[Len++]=0;
  while(Len--)
    putchar(Data[Len]+48);
  putchar('\n');
}

const int SG[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

bool OK[40000];

void Init()
{
  for(int i=1;i<=40000;i++)
    OK[i]=true;
  for(int i=2;i<=40000;i++)
    {
      int S=i*i;
      while(S<=40000)
        {
          OK[S]=false;
          S*=i;
        }
    }
}

double Pow(double A,int P)
{
  double S=1;
  for(int i=0;i<P;i++)
    S*=A;
  return S;
}

int Solve(int N,int P)
{
  int Ans=0;
  for(int i=2;Pow(i,P)<=N;i++)
    Ans+=OK[i];
  return Ans;
}

int main()
{
  Init();
  int N=Get();
  static int A[30];
  A[1]=N;
  for(int i=2;i<30;i++)
    {
      A[i]=Solve(N,i)-Solve(N,i+1);
      A[1]-=A[i]*i;
    }
  int Sum=0;
  for(int i=1;i<30;i++)
    if(A[i]&1)
      Sum^=SG[i];
  if(Sum)
    cout<<"Vasya"<<endl;
  else
    cout<<"Petya"<<endl;
  return 0;
}