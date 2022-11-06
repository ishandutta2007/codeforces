//program 156D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Parent[100000],Size[100000],A[100000];

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

int main()
{
  int N,M,P;cin>>N>>M>>P;
  for(int i=0;i<N;i++)Parent[i]=i;
  for(int i=0;i<N;i++)Size[i]=1;
  for(int i=0;i<M;i++)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      int U=Root(X),V=Root(Y);
      if(U!=V){Parent[U]=V;Size[V]+=Size[U];}
    }
  int Total=0;for(int i=0;i<N;i++)if(Root(i)==i)A[Total++]=Size[i];
  if(Total==1){cout<<(1%P)<<endl;return 0;}
  long long Ans=1,Sum=0;
  for(int i=0;i<Total;i++){Ans=Ans*A[i]%P;Sum=(Sum+A[i])%P;}
  for(int i=0;i<Total-2;i++)Ans=Ans*Sum%P;
  cout<<Ans<<endl;
  return 0;
}