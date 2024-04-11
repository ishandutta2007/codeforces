//program 108E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int Pos[16],Must[16];
bool Flag[65536];
long long F[65536];
int Log[65536];

long long DP(int X,int Mask)
{
  if(X==N)return 1;
  if(Flag[Mask])return F[Mask];
  Flag[Mask]=true;F[Mask]=0;
  int T=Mask;
  while(T)
    {
      int P=T&(-T),V=Log[P];T^=P;
      if(Pos[X]!=-1&&Pos[X]!=V)continue;
      if(!(Must[V]&Mask))F[Mask]+=DP(X+1,Mask^P);
    }
  return F[Mask];
}

long long GetCount()
{
  for(int i=0;i<(1<<N);i++)Flag[i]=false;
  return DP(0,(1<<N)-1);
}

int main()
{
  int M;long long K;cin>>N>>K>>M;K-=2000;
  for(int i=0;i<N;i++)Log[1<<i]=i;
  memset(Must,0,sizeof(Must));
  while(M--)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      Must[Y]|=1<<X;
    }
  for(int i=0;i<N;i++)Pos[i]=-1;
  if(GetCount()<K){cout<<"The times have changed"<<endl;return 0;}
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(Pos[j]==-1)
        {
          Pos[j]=i;long long T=GetCount();
          if(K>T)K-=T;else break;
          Pos[j]=-1;
        }
  int Ans[16];for(int i=0;i<N;i++)Ans[Pos[i]]=i+1;
  for(int i=0;i<N;i++)cout<<Ans[i]<<((i==N-1)?'\n':' ');
  return 0;
}