//program 151D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int P[2000];

int Root(int X)
{
  return (P[X]==X)?X:(P[X]=Root(P[X]));
}

int main()
{
  int N,M,K;cin>>N>>M>>K;
  for(int i=0;i<N;i++)P[i]=i;
  for(int i=0,j=K-1;j<N;i++,j++)
    for(int L=i,R=j;L<R;L++,R--)
      P[Root(L)]=Root(R);
  long long Ans=1;
  for(int i=0;i<N;i++)if(Root(i)==i)Ans=Ans*M%1000000007;
  cout<<Ans<<endl;
  return 0;
}