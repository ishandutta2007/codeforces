//program 258-C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int Mod=1000000007;

int A[100000];

int Find(int N,int X)
{
  if(A[N-1]<X)
    return 0;
  int Left=0,Right=N-1;
  while(Left<Right)
    {
      int Mid=(Left+Right)/2;
      if(A[Mid]>=X)
        Right=Mid;
      else
        Left=Mid+1;
    }
  return N-Left;
}

long long Pow(long long A,long long B)
{
  if(!B)
    return 1;
  long long T=Pow(A*A%Mod,B/2);
  if(B&1)
    T=T*A%Mod;
  return T;
}

int main()
{
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&A[i]);
  sort(A,A+N);
  long long Ans=1;
  for(int i=2;i<=100000;i++)
    {
      int M=0;
      static int X[1000];
      for(int j=1;j*j<=i;j++)
        if(!(i%j))
          X[M++]=j;
      int Start=M-1;
      if(X[Start]*X[Start]==i)
        Start--;
      while(Start>=0)
        {
          X[M++]=i/X[Start];
          Start--;
        }
      static int Count[1000];
      for(int j=0;j<M;j++)
        Count[j]=Find(N,X[j]);
      long long Good=1;
      for(int j=M-1,Last=0;j>=0;j--)
        {
          Good=Good*Pow(j+1,Count[j]-Last)%Mod;
          Last=Count[j];
        }
      long long Bad=1;
      for(int j=M-2,Last=0;j>=0;j--)
        {
          Bad=Bad*Pow(j+1,Count[j]-Last)%Mod;
          Last=Count[j];
        }
      Ans=(Ans+Good-Bad)%Mod;
      if(Ans<0)
        Ans+=Mod;
    }
  cout<<Ans<<endl;
  return 0;
}