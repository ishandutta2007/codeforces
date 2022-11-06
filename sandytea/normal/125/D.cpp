//program 125D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int S[30000],A[30000],B[30000];
bool Flag[30000];

bool AP()
{
  int P=0,Q=0;
  for(int i=0;i<N;i++)if(Flag[i])A[P++]=S[i];else B[Q++]=S[i];
  if(!Q)return false;
  for(int i=2;i<Q;i++)if(B[i]+B[i-2]!=B[i-1]*2)return false;
  for(int i=0;i<P;i++){cout<<A[i];putchar((i==P-1)?'\n':' ');}
  for(int i=0;i<Q;i++){cout<<B[i];putchar((i==Q-1)?'\n':' ');}
  return true;
}

bool Check(int X,int Y)
{
  int Last=Y,T1=S[X],T2=S[Y];
  memset(Flag,0,sizeof(Flag));
  Flag[X]=Flag[Y]=true;
  for(int i=2;i<N;i++)
    if(S[i]+T1==T2*2)
      {
        Flag[Last=i]=true;
        T1=T2;T2=S[i];
      }
  if(AP())return true;
  Flag[Last]=false;
  return AP();
}


int main()
{
  cin>>N;for(int i=0;i<N;i++)cin>>S[i];
  if(N==2)
    cout<<S[0]<<endl<<S[1]<<endl;
  else if(!Check(0,1))if(!Check(0,2))if(!Check(1,2))
    cout<<"No solution"<<endl;
  return 0;
}