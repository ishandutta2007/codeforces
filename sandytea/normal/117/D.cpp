//program 117D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

long long Mod,LB,UB;

long long GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  long long X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

void Output(long long X)
{
  int P=0,A[20];
  while(X){A[P++]=X%10;X/=10;}
  if(!P)A[P++]=0;
  while(P--)putchar(A[P]+48);
  putchar('\n');
}

long long Query(int Depth,long long Step,long long P,long long Q,long long Left,long long Right,long long L,long long R)
{
  if(LB>Q||UB<P)return 0;
  if(L==Left&&R==Right)
    {
      long long Min=0,Max=(Q-P)>>Depth,T;
      if(LB>P)Min=((LB-P-1)>>Depth)+1;
      if(UB<Q)Max=(UB-P)>>Depth;
      if(Min>Max)return 0;
      long long Count=Max-Min+1,S1=(Count%Mod)*(P%Mod)%Mod,X=Min+Max;
      if(!(X&1))X/=2;else Count/=2;
      Count%=Mod;X%=Mod;
      long long S2=Count*X%Mod*(Step%Mod)%Mod;
      return (S1+S2)%Mod;
    }
  long long Mid=(Left+Right)/2;
  if((Q-P)&Step)
    {
      if(R<=Mid)return Query(Depth+1,Step<<1,P,Q-Step,Left,Mid,L,R);
      if(L>Mid)return Query(Depth+1,Step<<1,P+Step,Q,Mid+1,Right,L,R);
      return (Query(Depth+1,Step<<1,P,Q-Step,Left,Mid,L,Mid)+Query(Depth+1,Step<<1,P+Step,Q,Mid+1,Right,Mid+1,R))%Mod;
    }
  else
    {
      if(R<=Mid)return Query(Depth+1,Step<<1,P,Q,Left,Mid,L,R);
      if(L>Mid)return Query(Depth+1,Step<<1,P+Step,Q-Step,Mid+1,Right,L,R);
      return (Query(Depth+1,Step<<1,P,Q,Left,Mid,L,Mid)+Query(Depth+1,Step<<1,P+Step,Q-Step,Mid+1,Right,Mid+1,R))%Mod;
    }
}

int main()
{
  long long N=GetNumber(),M=GetNumber();Mod=GetNumber();
  while(M--)
    {
      long long L=GetNumber(),R=GetNumber();LB=GetNumber();UB=GetNumber();
      Output(Query(0,1,1,N,1,N,L,R));
    }
  return 0;
}