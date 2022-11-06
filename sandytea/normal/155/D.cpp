//program 155D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int Total=0;
int Prime[9592],A[6];
bool Flag[100001];
set<int> List[9592];

bool IsPrime(int X)
{
  for(int i=0;i<Total&&Prime[i]*Prime[i]<=X;i++)if(X%Prime[i]==0)return false;
  return true;
}

int Add(int X)
{
  int T=X,Count=0;
  for(int i=0;i<Total&&Prime[i]*Prime[i]<=T;i++)
    if(T%Prime[i]==0)
      {
        while(T%Prime[i]==0)T/=Prime[i];
        A[Count++]=i;
      }
  if(T>1){int P=0;while(Prime[P]<T)P++;A[Count++]=P;}
  for(int i=0;i<Count;i++)
    if(!List[A[i]].empty())
      return *List[A[i]].begin();
  for(int i=0;i<Count;i++)List[A[i]].insert(X);
  Flag[X]=true;return -1;
}

void Delete(int X)
{
  int T=X;
  for(int i=0;i<Total&&Prime[i]*Prime[i]<=T;i++)
    if(T%Prime[i]==0)
      {
        while(T%Prime[i]==0)T/=Prime[i];
        List[i].erase(X);
      }
  if(T>1){int P=0;while(Prime[P]<T)P++;List[P].erase(X);}
  Flag[X]=false;
}

int main()
{
  int N,M;cin>>N>>M;
  for(int i=2;i<=N;i++)if(IsPrime(i))Prime[Total++]=i;
  memset(Flag,0,sizeof(Flag));
  while(M--)
    {
      char c=getchar();while(c!='+'&&c!='-')c=getchar();
      int X;cin>>X;
      if(c=='+')
        if(Flag[X])
          cout<<"Already on"<<endl;
        else
          {
            int T=Add(X);
            if(T==-1)cout<<"Success"<<endl;else cout<<"Conflict with "<<T<<endl;
          }
      if(c=='-')
        if(Flag[X])
          {Delete(X);cout<<"Success"<<endl;}
        else
          cout<<"Already off"<<endl;
    }
  return 0;
}