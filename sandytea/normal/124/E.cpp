//program 124E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const long long inf=2000000000000000000LL;

int A[200];

long long Calc(long long A,long long B)
{
  return (A>inf-B)?inf:(A+B);
}

long long Count(int N)
{
  long long F[200][200];
  memset(F,0,sizeof(F));F[0][0]=1;
  for(int i=0;i<N;i++)
    for(int j=0;j<=N;j++)
      {
        if(A[i]!=-1&&j)F[i+1][j]=Calc(F[i+1][j],F[i][j-1]);
        if(A[i]!=1)F[i+1][j]=Calc(F[i+1][j],F[i][j+1]);
      }
  return F[N][0];
}

int main()
{
  int M,N,P[100][100];long long K;cin>>M>>N>>K;
  for(int i=0;i<M;i++)for(int j=0;j<N;j++)cin>>P[i][j];
  int Len=M+N-1,Q[200];for(int i=0;i<Len;i++)Q[i]=M*N;
  for(int i=0;i<M;i++)for(int j=0;j<N;j++)Q[i+j]=min(Q[i+j],P[i][j]);
  int Data[200];for(int i=0;i<Len;i++)Data[i]=i;
  for(int i=0;i<Len;i++)
    for(int j=i+1;j<Len;j++)
      if(Q[Data[i]]>Q[Data[j]])
        {int Tmp=Data[i];Data[i]=Data[j];Data[j]=Tmp;}
  memset(A,0,sizeof(A));
  for(int i=0;i<Len;i++)
    {
      A[Data[i]]=1;
      long long Tmp=Count(Len);
      if(K>Tmp){A[Data[i]]=-1;K-=Tmp;}
    }
  for(int i=0;i<M;i++)
    {
      for(int j=0;j<N;j++)putchar((A[i+j]==1)?'(':')');
      putchar('\n');
    }
  return 0;
}