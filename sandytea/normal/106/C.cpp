//program 106C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,M,Cost[11],Money[11],Max[11];
  cin>>N>>M>>Cost[0]>>Money[0];
  for(int i=1;i<=M;i++){int A,B;cin>>A>>B>>Cost[i]>>Money[i];Max[i]=A/B;}
  int F[11][1001];
  for(int i=0;i<=N;i++)F[0][i]=i/Cost[0]*Money[0];
  for(int i=1;i<=M;i++)
    for(int j=0;j<=N;j++)
      {
        F[i][j]=F[i-1][j];
        for(int k=1;k<=Max[i];k++)
          if(j>=k*Cost[i])
            F[i][j]=max(F[i][j],F[i-1][j-k*Cost[i]]+k*Money[i]);
      }
  cout<<F[M][N]<<endl;
  return 0;
}