//program 159D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;int N=S.size();
  int G[2000][2000];memset(G,0,sizeof(G));
  for(int i=0;i<N;i++)G[i][i]=true;
  for(int i=1;i<N;i++)G[i][i-1]=true;
  for(int Step=1;Step<N;Step++)
    for(int i=0,j=Step;j<N;i++,j++)
      G[i][j]=(S[i]==S[j])&&(G[i+1][j-1]);
  long long C0[2000];memset(C0,0,sizeof(C0));
  for(int i=0;i<N;i++)for(int j=i;j<N;j++)C0[i]+=G[i][j];
  long long C1[2000];memset(C1,0,sizeof(C1));
  for(int i=0;i<N;i++)for(int j=i;j<N;j++)C1[j]+=G[i][j];
  long long Ans=0;
  for(int i=1;i<N;i++)
    for(int j=0;j<i;j++)
      Ans+=C0[i]*C1[j];
  cout<<Ans<<endl;
  return 0;
}