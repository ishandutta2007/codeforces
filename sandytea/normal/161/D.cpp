//program 161D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> G[50000];
int Queue[50000],Parent[50000];
long long Down[50000][501],Up[50000][501];

int main()
{
  int N,K;cin>>N>>K;
  for(int i=1;i<N;i++)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      G[X].push_back(Y);G[Y].push_back(X);
    }
  int F=0,R=1;Queue[0]=0;Parent[0]=-1;
  while(R<N)
    {
      int V=Queue[F++];
      for(int i=0;i<G[V].size();i++)
        if(G[V][i]!=Parent[V])
          Parent[Queue[R++]=G[V][i]]=V;
    }
  memset(Down,0,sizeof(Down));
  for(int i=0;i<N;i++)Down[i][0]=1;
  for(int i=N-1;i>=0;i--)
    {
      int V=Queue[i];
      for(int j=1;j<=K;j++)
        for(int k=0;k<G[V].size();k++)
          if(G[V][k]!=Parent[V])
            Down[V][j]+=Down[G[V][k]][j-1];
    }
  memset(Up,0,sizeof(Up));
  for(int i=0;i<N;i++)Up[i][0]=1;
  for(int i=1;i<N;i++)
    {
      int V=Queue[i];
      for(int j=1;j<=K;j++)
        {
          Up[V][j]=Up[Parent[V]][j-1]+Down[Parent[V]][j-1];
          if(j>1)Up[V][j]-=Down[V][j-2];else Up[V][j]--;
        }
    }
  long long Ans=0;
  for(int i=0;i<N;i++)Ans+=Up[i][K]+Down[i][K];
  cout<<Ans/2<<endl;
  return 0;
}