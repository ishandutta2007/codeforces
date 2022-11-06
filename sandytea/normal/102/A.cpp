//program 102A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int main()
{
  int N,M;cin>>N>>M;
  int V[100];for(int i=0;i<N;i++)cin>>V[i];
  bool G[100][100];memset(G,0,sizeof(G));
  while(M--){int X,Y;cin>>X>>Y;X--;Y--;G[X][Y]=G[Y][X]=true;}
  int Ans=inf;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      for(int k=0;k<N;k++)
        if(G[i][j]&&G[i][k]&&G[j][k])
          Ans=min(Ans,V[i]+V[j]+V[k]);
  cout<<((Ans==inf)?-1:Ans)<<endl;
  return 0;
}