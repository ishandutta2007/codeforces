//program 158E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int F[4000][4001];

int main()
{
  int N,K;cin>>N>>K;
  if(N==K){cout<<86400<<endl;return 0;}
  int X[4000],T[4000];for(int i=0;i<N;i++)cin>>X[i]>>T[i];
  for(int i=0;i<N;i++)for(int j=0;j<=K;j++)F[i][j]=(i<j)?1:inf;
  F[0][0]=X[0]+T[0];
  for(int i=1;i<N;i++)
    for(int j=0;j<=min(i+1,K);j++)
      F[i][j]=min(j?F[i-1][j-1]:inf,max(F[i-1][j],X[i])+T[i]);
  int Ans=max(X[0]-1,86401-F[N-1][K]);
  for(int i=1;i<N;i++)Ans=max(Ans,X[i]-F[i-1][K]);
  cout<<Ans<<endl;
  return 0;
}