//program 95E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int Parent[100000],Size[100000];

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

bool Lucky(int X)
{
  if(!X)return true;
  if(X%10!=4&&X%10!=7)return false;
  return Lucky(X/10);
}

int main()
{
  int N,M;cin>>N>>M;
  for(int i=0;i<N;i++)Parent[i]=i;
  for(int i=0;i<N;i++)Size[i]=1;
  while(M--)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      int A=Root(X),B=Root(Y);
      if(A!=B){Parent[B]=A;Size[A]+=Size[B];}
    }
  int Count[100001];memset(Count,0,sizeof(Count));
  for(int i=0;i<N;i++)if(Root(i)==i)Count[Size[i]]++;
  int Total=0,X[2000],Y[2000];
  for(int i=1;i<=N;i++)
    if(Count[i])
      {
        int T=Count[i],K=1;
        while(T>K){Total++;X[Total]=i*K;Y[Total]=K;T-=K;K*=2;}
        Total++;X[Total]=i*T;Y[Total]=T;
      }
  int F[100001];F[0]=0;for(int i=1;i<=N;i++)F[i]=inf;
  for(int i=1;i<=Total;i++)
    for(int j=N;j>=X[i];j--)
      F[j]=min(F[j],F[j-X[i]]+Y[i]);
  int Ans=inf;
  for(int i=1;i<=N;i++)if(Lucky(i))Ans=min(Ans,F[i]-1);
  cout<<((Ans>N)?-1:Ans)<<endl;
  return 0;
}