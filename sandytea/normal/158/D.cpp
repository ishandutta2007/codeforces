//program 158D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int X[20000],S[20000];

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)cin>>X[i];
  int Ans=0;for(int i=0;i<N;i++)Ans+=X[i];
  for(int i=2;i<=N/3;i++)
    if(N%i==0)
      {
        memset(S,0,sizeof(S));
        for(int j=0;j<N;j++)S[j%i]+=X[j];
        for(int j=0;j<i;j++)Ans=max(Ans,S[j]);
      }
  cout<<Ans<<endl;
  return 0;
}