//program 118D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int P=100000000;

int F[101][101][2][11];

int main()
{
  int M,N,L1,L2;cin>>M>>N>>L1>>L2;
  memset(F,0,sizeof(F));
  for(int i=0;i<=M;i++)
    for(int j=0;j<=N;j++)
      {
        for(int k=0;k<=L1;k++)
          {
            if(i&&k<L1)F[i][j][0][k]+=F[i-1][j][0][k+1];
            if(j)F[i][j][0][k]+=F[i][j-1][1][1];
            if(F[i][j][0][k]>=P)F[i][j][0][k]-=P;
            if(!i&&!j)F[i][j][0][k]=1;
          }
        for(int k=0;k<=L2;k++)
          {
            if(i)F[i][j][1][k]+=F[i-1][j][0][1];
            if(j&&k<L2)F[i][j][1][k]+=F[i][j-1][1][k+1];
            if(F[i][j][1][k]>=P)F[i][j][1][k]-=P;
            if(!i&&!j)F[i][j][1][k]=1;
          }
      }
  cout<<F[M][N][0][0]<<endl;
  return 0;
}