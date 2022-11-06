//program 147B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int inf=1000000000;

int F[10][300][300],G[300][300],H[300][300];

void Init(int A[300][300])
{
  for(int i=0;i<300;i++)
    for(int j=0;j<300;j++)
      A[i][j]=(i==j)?0:-inf;
}

bool Check(int P,int N)
{
  Init(G);
  while(P)
    {
      int Q=P&(-P);P-=Q;
      Q=int(log(Q)/log(2)+0.1);
      Init(H);
      for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
          for(int k=0;k<N;k++)
            H[i][j]=max(H[i][j],G[i][k]+F[Q][k][j]);
      for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
          G[i][j]=H[i][j];
    }
  for(int i=0;i<N;i++)if(G[i][i]>0)return true;
  return false;
}

int main()
{
  int N,M;cin>>N>>M;
  for(int i=0;i<10;i++)Init(F[i]);
  while(M--)
    {
      int X,Y,W1,W2;cin>>X>>Y>>W1>>W2;
      X--;Y--;F[0][X][Y]=W1;F[0][Y][X]=W2;
    }
  for(int T=1;T<10;T++)
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        for(int k=0;k<N;k++)
          F[T][i][j]=max(F[T][i][j],F[T-1][i][k]+F[T-1][k][j]);
  if(!Check(N,N))
    cout<<0<<endl;
  else
    {
      int Left=2,Right=N;
      while(Left<Right)
        {
          int Mid=(Left+Right)/2;
          if(Check(Mid,N))Right=Mid;else Left=Mid+1;
        }
      cout<<Left<<endl;
    }
  return 0;
}