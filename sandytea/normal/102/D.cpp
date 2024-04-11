//program 102D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int P=1000000007;

int L[200000],R[200000],Data[200000],X[200000],F[200000],Sum[200000];
vector<int> G[200000];

int Find(int T,int N)
{
  int Left=1,Right=N;
  while(Left<Right)
    {
      int Mid=(Left+Right)/2;
      if(X[Mid]<T)Left=Mid+1;else Right=Mid;
    }
  return Left;
}

int main()
{
  int N,M;cin>>N>>M;
  for(int i=0;i<M;i++)cin>>L[i]>>R[i];
  for(int i=0;i<M;i++)Data[i]=R[i];Data[M]=0;sort(Data,Data+M+1);
  int Total=0;for(int i=0;i<=M;i++)if(!i||Data[i]!=Data[i-1])X[++Total]=Data[i];
  for(int i=0;i<M;i++)G[Find(R[i],Total)].push_back(Find(L[i],Total));
  F[1]=1;Sum[1]=1;
  for(int i=2;i<=Total;i++)
    {
      F[i]=0;
      for(int j=0;j<G[i].size();j++)
        {
          F[i]=(F[i]+Sum[i-1]-Sum[G[i][j]-1])%P;
          if(F[i]<0)F[i]+=P;
        }
      Sum[i]=(Sum[i-1]+F[i])%P;
    }
  cout<<((X[Total]==N)?F[Total]:0)<<endl;
  return 0;
}