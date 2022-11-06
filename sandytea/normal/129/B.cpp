//program 129B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
bool G[100][100];
int Degree[100];

bool Cut()
{
  bool Flag[100],T=false;
  for(int i=0;i<N;i++){Flag[i]=(Degree[i]==1);T=T||Flag[i];}
  for(int i=0;i<N;i++)
    if(Flag[i])
      for(int j=0;j<N;j++)
        if(i==j||G[i][j])
          Degree[j]--;
  return T;
}

int main()
{
  int M;cin>>N>>M;
  memset(G,0,sizeof(G));
  memset(Degree,0,sizeof(Degree));
  while(M--)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      G[X][Y]=G[Y][X]=true;
      Degree[X]++;Degree[Y]++;
    }
  int Ans=0;
  while(Cut())Ans++;
  cout<<Ans<<endl;
  return 0;
}