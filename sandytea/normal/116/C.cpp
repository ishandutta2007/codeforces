//program 116C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int P[2000];

int Depth(int X)
{
  return (P[X]==-1)?1:(Depth(P[X])+1);
}

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++){cin>>P[i];if(P[i]>0)P[i]--;}
  int Ans=0;
  for(int i=0;i<N;i++)Ans=max(Ans,Depth(i));
  cout<<Ans<<endl;
  return 0;
}