//program 148E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int G[101][101][101],C[100][10001],F[101][10001];

int main()
{
  int N,K,L[100];cin>>N>>K;
  for(int i=0;i<N;i++)
    {
      int A[100];
      cin>>L[i];for(int j=0;j<L[i];j++)cin>>A[j];
      memset(G,0,sizeof(G));
      for(int T=1;T<=L[i];T++)
        for(int Len=0;Len<L[i];Len++)
          for(int Left=0,Right=Len;Right<L[i];Left++,Right++)
            G[T][Left][Right]=max(A[Left]+G[T-1][Left+1][Right],A[Right]+G[T-1][Left][Right-1]);
      for(int j=0;j<=K;j++)if(j>L[i])C[i][j]=0;else C[i][j]=G[j][0][L[i]-1];
    }
  memset(F,0,sizeof(F));
  for(int i=N-1;i>=0;i--)
    for(int j=0;j<=K;j++)
      for(int k=0;k<=j&&k<=L[i];k++)
        F[i][j]=max(F[i][j],F[i+1][j-k]+C[i][k]);
  cout<<F[0][K]<<endl;
  return 0;
}