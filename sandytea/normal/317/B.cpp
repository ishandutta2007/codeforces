//program 317-B

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

const int S=80;

int main()
{
  static int DP[2][S*2+1][S*2+1];
  memset(DP,0,sizeof(DP));
  DP[0][S][S]=Get();
  static int Ans[S*2+1][S*2+1];
  for(int i=1;i<=10000;i++)
    {
      memset(DP[i&1],0,sizeof(DP[i&1]));
      for(int j=0;j<=S*2;j++)
        for(int k=0;k<=S*2;k++)
          {
            int T=DP[~i&1][j][k]/4;
            if(T)
              {
                DP[i&1][j+1][k]+=T;
                DP[i&1][j-1][k]+=T;
                DP[i&1][j][k+1]+=T;
                DP[i&1][j][k-1]+=T;
              }
            DP[i&1][j][k]+=DP[~i&1][j][k]%4;
          }
      bool Find=false;
      for(int j=0;!Find&&j<=S*2;j++)
        for(int k=0;!Find&&k<=S*2;k++)
          if(DP[0][j][k]!=DP[1][j][k])
            Find=true;
      if(!Find)
        {
          for(int j=0;j<=S*2;j++)
            for(int k=0;k<=S*2;k++)
              Ans[j][k]=DP[i&1][j][k];
          break;
        }
    }
  int M=Get();
  while(M--)
    {
      int X=Get(),Y=Get();
      if(X<-S||X>S||Y<-S||Y>S)
        Output(0);
      else
        Output(Ans[X+S][Y+S]);
    }
  return 0;
}