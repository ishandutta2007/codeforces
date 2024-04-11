//program 93E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX=500000;

int A[100],F[MAX][100];

long long DP(long long N,int K)
{
  if(K<0||!N)return N;
  if(N<MAX&&F[N][K]!=-1)return F[N][K];
  long long T=DP(N,K-1)-DP(N/A[K],K-1);
  if(N<MAX)F[N][K]=T;return T;
}

int main()
{
  long long N;int K;cin>>N>>K;
  for(int i=0;i<K;i++)cin>>A[i];sort(A,A+K);
  for(int i=0;i<MAX;i++)for(int j=0;j<K;j++)F[i][j]=-1;
  cout<<DP(N,K-1)<<endl;
  return 0;
}