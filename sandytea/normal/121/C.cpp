//program 121C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const long long Fac[14]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800LL};

int Total,Data[5000];

bool Lucky(int T)
{
  while(T){if(T%10!=4&&T%10!=7)return false;T/=10;}return true;
}

void Init()
{
  Total=0;
  for(int i=1;i<=9;i++)
    for(int j=0;j<(1<<i);j++)
      {int S=0;for(int k=0;k<i;k++)S=S*10+((j&(1<<k))?4:7);Data[Total++]=S;}
  sort(Data,Data+Total);
}

int Count(int N)
{
  if(Data[Total-1]<=N)return Total;
  int P=0;while(Data[P]<=N)P++;return P;
}

int Count1(int N,int K)
{
  if(K>=Fac[N])return -1;
  int Ans=0,Kth[20],A[20];for(int i=1;i<=N;i++)Kth[i]=i;
  for(int i=1;i<=N;i++)
    {
      A[i]=Kth[K/Fac[N-i]+1];K%=Fac[N-i];
      if(Lucky(i)&&Lucky(A[i]))Ans++;
      int P=1;while(Kth[P]!=A[i])P++;
      for(int j=P;j<=N-i;j++)Kth[j]=Kth[j+1];
    }
  return Ans;
}

int Count2(int N,int K)
{
  int Ans=Count(N),Kth[20],A[20];for(int i=1;i<=13;i++)Kth[i]=N+i;
  for(int i=1;i<=13;i++)
    {
      A[i]=Kth[K/Fac[13-i]+1];K%=Fac[13-i];
      if(Lucky(N+i)&&Lucky(A[i]))Ans++;
      int P=1;while(Kth[P]!=A[i])P++;
      for(int j=P;j<=13-i;j++)Kth[j]=Kth[j+1];
    }
  return Ans;
}

int main()
{
  Init();int N,K;cin>>N>>K;K--;
  cout<<((N<=13)?Count1(N,K):Count2(N-13,K))<<endl;
  return 0;
}