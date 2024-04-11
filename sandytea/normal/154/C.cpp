//program 154C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const long long Mod=1996032019961021LL;

int N,M;
long long Pow[1000000],Hash[1000000];
int X[1000000],Y[1000000];

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

long long Count()
{
  for(int i=0;i<M;i++)
    {
      Hash[X[i]]=(Hash[X[i]]+Pow[Y[i]])%Mod;
      Hash[Y[i]]=(Hash[Y[i]]+Pow[X[i]])%Mod;
    }
  sort(Hash,Hash+N);
  int P=0;long long Sum=0;
  while(P<N)
    {
      long long T=1;while(P+T<N&&Hash[P]==Hash[P+T])T++;
      P+=T;Sum+=T*(T-1)/2;
    }
  return Sum;
}

int main()
{
  N=GetNumber();M=GetNumber();
  Pow[0]=1;for(int i=1;i<N;i++)Pow[i]=Pow[i-1]*2%Mod;
  for(int i=0;i<M;i++){X[i]=GetNumber()-1;Y[i]=GetNumber()-1;}
  long long Ans=0;
  for(int i=0;i<N;i++)Hash[i]=0;Ans+=Count();
  for(int i=0;i<N;i++)Hash[i]=Pow[i];Ans+=Count();
  cout<<Ans<<endl;
  return 0;
}