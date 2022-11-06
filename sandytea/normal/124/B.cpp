//program 124B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int M,N,Ans,A[8];
string S[8];
bool Flag[8];

void DFS(int Depth)
{
  if(Depth==N)
    {
      int Max=-inf,Min=inf;
      for(int i=0;i<M;i++){Max=max(Max,A[i]);Min=min(Min,A[i]);}
      Ans=min(Ans,Max-Min);
      return;
    }
  for(int i=0;i<N;i++)
    if(!Flag[i])
      {
        for(int j=0;j<M;j++)A[j]=A[j]*10+S[j][i]-48;
        Flag[i]=true;
        DFS(Depth+1);
        for(int j=0;j<M;j++)A[j]/=10;
        Flag[i]=false;
      }
}

int main()
{
  cin>>M>>N;
  for(int i=0;i<M;i++)cin>>S[i];
  memset(A,0,sizeof(A));
  memset(Flag,0,sizeof(Flag));
  Ans=1000000000;DFS(0);cout<<Ans<<endl;
  return 0;
}