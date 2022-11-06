//program 96E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int Mod=1000000007;
const int C1[10]={0,0,0,0,0,1,1,1,2,2};
const int C2[10]={0,0,0,0,1,0,0,1,0,0};
const int C3[10]={0,1,2,3,4,4,5,6,6,7};
const int C4[10]={1,1,1,1,0,1,1,0,1,1};

int Len,K;
int A[1001];
bool Flag[1001][1001];
long long Pow[1001],Sum[1001];
long long F[1001][1001];

long long Check(long long X)
{
  while(X<0)X+=Mod;
  return X%Mod;
}

long long DP(int X,int Last,bool Smaller)
{
  if(X<0)return 0;if(Last>K)Last=0;
  if(Smaller&&Flag[X][Last])return F[X][Last];
  if(Smaller)Flag[X][Last]=true;
  long long Ans;int T=A[Len-1-X];
  if(Smaller)
    if(!Last)
      Ans=DP(X-1,1,1)*2+DP(X-1,0,1)*8;
    else
      Ans=Pow[X]*2+DP(X-1,Last+1,1)*8;
  else
    if(!Last)
      Ans=DP(X-1,1,1)*C1[T]+(C2[T]?(DP(X-1,1,0)*C2[T]):0)+DP(X-1,0,1)*C3[T]+(C4[T]?(DP(X-1,0,0)*C4[T]):0);
    else
      Ans=Pow[X]*C1[T]+(Sum[X]+1)*C2[T]+DP(X-1,Last+1,1)*C3[T]+(C4[T]?(DP(X-1,Last+1,0)*C4[T]):0);
  return Smaller?(F[X][Last]=Check(Ans)):Check(Ans);
}

long long Count(string S)
{
  Len=S.size();
  for(int i=0;i<Len;i++)A[i]=S[i]-48;
  Pow[0]=1;for(int i=1;i<Len;i++)Pow[i]=Check(Pow[i-1]*10);
  Sum[0]=0;for(int i=1;i<Len;i++)Sum[i]=Check(Sum[i-1]+Pow[i-1]*A[Len-i]);
  return DP(Len-1,0,false);
}

string Minus(string S)
{
  int N=S.size(),P=N-1;
  while(S[P]=='0')S[P--]='9';S[P]--;
  if(S[0]=='0'&&S.size()>1){string T=S;S="";for(int i=1;i<N;i++)S+=T[i];}
  return S;
}

int main()
{
  int Test;cin>>Test>>K;
  memset(Flag,0,sizeof(Flag));
  while(Test--)
    {
      string LB,UB;cin>>LB>>UB;
      cout<<Check(Count(UB)-Count(Minus(LB)))<<endl;
    }
  return 0;
}