//program 297-D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Get()
{
  char c;
  while(c=getchar(),c<'0'||c>'9');
  int X=0;
  while(c>='0'&&c<='9')
    {
      X=X*10+c-48;
      c=getchar();
    }
  return X;
}

void Output(int X)
{
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

bool Read()
{
  char c;
  while(c=getchar(),c!='N'&&c!='E');
  return c=='E';
}

int main()
{
  int M=Get(),N=Get(),K=Get(),Total=M*N*2-M-N;
  static bool A[1000][1000],B[1000][1000];
  for(int i=0;i<M;i++)
    {
      for(int j=0;j<N-1;j++)
        A[i][j]=Read();
      if(i+1<M)
        for(int j=0;j<N;j++)
          B[i][j]=Read();
    }
  if(K==1)
    {
      int Count=0;
      for(int i=0;i<M;i++)
        for(int j=0;j<N-1;j++)
          if(A[i][j])
            Count++;
      for(int i=0;i<M-1;i++)
        for(int j=0;j<N;j++)
          if(B[i][j])
            Count++;
      if(4*Count<3*Total)
        printf("NO\n");
      else
        {
          printf("YES\n");
          for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
              {
                putchar('1');
                putchar((j+1==N)?'\n':' ');
              }
        }
      return 0;
    }
  printf("YES\n");
  static bool Ans[1000][1000];
  if(M*(N-1)>=N*(M-1))
    for(int i=0;i<M;i++)
      {
        Ans[i][0]=0;
        for(int j=1;j<N;j++)
          if(A[i][j-1])
            Ans[i][j]=Ans[i][j-1];
          else
            Ans[i][j]=Ans[i][j-1]^1;
        if(!i)
          continue;
        int Count=0;
        for(int j=0;j<N;j++)
          if(B[i-1][j]^(Ans[i][j]==Ans[i-1][j]))
            Count++;
        if(Count>N/2)
          for(int j=0;j<N;j++)
            Ans[i][j]^=1;
      }
  else
    for(int i=0;i<N;i++)
      {
        Ans[0][i]=0;
        for(int j=1;j<M;j++)
          if(B[j-1][i])
            Ans[j][i]=Ans[j-1][i];
          else
            Ans[j][i]=Ans[j-1][i]^1;
        if(!i)
          continue;
        int Count=0;
        for(int j=0;j<M;j++)
          if(A[j][i-1]^(Ans[j][i]==Ans[j][i-1]))
            Count++;
        if(Count>M/2)
          for(int j=0;j<M;j++)
            Ans[j][i]^=1;
      }
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      {
        putchar(Ans[i][j]+49);
        putchar((j+1==N)?'\n':' ');
      }
  return 0;
}