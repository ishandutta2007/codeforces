//program 129E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int P=1000000007;

long long F[1001][1001],Sum[1001][1001];

int main()
{
  long long M,N,K;cin>>M>>N>>K;
  memset(F,0,sizeof(F));memset(Sum,0,sizeof(Sum));
  for(int i=1;i<=max(M,N);i++)F[0][i]=1;
  for(int i=1;i<=max(M,N);i++)Sum[0][i]=i;
  for(int i=1;i<=K;i++)
    for(int j=2;j<=max(M,N);j++)
      {
        F[i][j]=(F[i][j-1]+Sum[i-1][j-2])%P;
        Sum[i][j]=(Sum[i][j-1]+F[i][j])%P;
      }
  cout<<(F[K][M]*F[K][N]%P)<<endl;
  return 0;
}