//program 134B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int inf=1000000000;

int Calc(int X,int Y)
{
  if(X==1)return Y-1;
  if(Y%X==0)return inf;
  return Calc(Y%X,X)+Y/X;
}

int main()
{
  int N,Ans=inf;cin>>N;
  for(int i=1;i<=N;i++)Ans=min(Ans,Calc(i,N));
  cout<<Ans<<endl;
  return 0;
}