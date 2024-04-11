//program 149D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int MOD=1000000007;

string S;
int Pair[700];
bool Flag[700][700][2][2];
long long F[700][700][2][2];

long long Count(int L,int R,int P,int Q)
{
  if(L>R)return 1;
  if(Flag[L][R][P][Q])return F[L][R][P][Q];
  Flag[L][R][P][Q]=true;
  long long T1,T2;
  if(Pair[L]==R)
    return F[L][R][P][Q]=((P?1:2)*Count(L+1,R-1,1,0)+(Q?1:2)*Count(L+1,R-1,0,1))%MOD;
  else
    {
      long long T1=Count(L+1,Pair[L]-1,1,0)*Count(Pair[L]+1,R,0,Q);
      long long T2=Count(L+1,Pair[L]-1,0,1)*Count(Pair[L]+1,R,1,Q);
      return F[L][R][P][Q]=((P?1:2)*T1+2*T2)%MOD;
    }
}

int main()
{
  cin>>S;int N=S.size();
  int Top=0,Stack[700];
  for(int i=0;i<N;i++)
    if(S[i]=='(')
      Stack[Top++]=i;
    else
      Pair[Stack[--Top]]=i;
  memset(Flag,0,sizeof(Flag));
  cout<<Count(0,N-1,0,0)<<endl;
  return 0;
}