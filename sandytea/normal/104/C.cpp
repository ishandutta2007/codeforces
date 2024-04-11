//program 104C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Parent[100];

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

int main()
{
  int N,M;cin>>N>>M;
  if(N!=M){cout<<"NO"<<endl;return 0;}
  for(int i=0;i<N;i++)Parent[i]=i;
  while(M--)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      Parent[Root(X)]=Root(Y);
    }
  for(int i=1;i<N;i++)
    if(Root(i)!=Root(i-1))
      {cout<<"NO"<<endl;return 0;}
  cout<<"FHTAGN!"<<endl;
  return 0;
}