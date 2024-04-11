//program 317-A

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

int main()
{
  long long X,Y,M;
  cin>>X>>Y>>M;
  if(X>=M||Y>=M)
    {
      cout<<0<<endl;
      return 0;
    }
  if(X<Y)
    swap(X,Y);
  if(X<=0)
    {
      cout<<-1<<endl;
      return 0;
    }
  long long Ans=0;
  if(Y<0)
    {
      Ans=-Y/X;
      Y+=Ans*X;
    }
  while(X<M&&Y<M)
    {
      if(X<Y)
        X+=Y;
      else
        Y+=X;
      Ans++;
    }
  cout<<Ans<<endl;
  return 0;
}