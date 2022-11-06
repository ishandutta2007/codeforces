//program 110E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Parent[100000];
long long Count[100000];

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

bool Lucky(int T)
{
  if(T==4||T==7)return true;
  if(T%10!=4&&T%10!=7)return false;
  return Lucky(T/10);
}

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)Parent[i]=i;
  for(int i=1;i<N;i++)
    {
      int X,Y,W;cin>>X>>Y>>W;X--;Y--;
      if(!Lucky(W))Parent[Root(X)]=Root(Y);
    }
  memset(Count,0,sizeof(Count));
  for(int i=0;i<N;i++)Count[Root(i)]++;
  long long Ans=0;
  for(int i=0;i<N;i++)Ans+=Count[i]*(N-Count[i])*(N-Count[i]-1);
  cout<<Ans<<endl;
  return 0;
}