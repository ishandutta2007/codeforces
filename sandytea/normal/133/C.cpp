//program 133C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Reverse(int X)
{
  int S=0;
  for(int i=0;i<8;i++)
    {
      S=S*2+X%2;
      X/=2;
    }
  return S;
}

int main()
{
  int Ans=0,X;
  while(X=getchar(),X>=32&&X<=126)
    {
      int T=Reverse(X);
      cout<<(Ans-T+256)%256<<endl;
      Ans=T;
    }
  return 0;
}