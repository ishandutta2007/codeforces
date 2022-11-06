//program 169C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int Mod=1000000007;

char S[5000],T[5000];
long long F[5001][5001];

int main()
{
  int M=0,N=0;char c;
  while(c=getchar(),c>='a'&&c<='z')S[M++]=c;
  while(c=getchar(),c>='a'&&c<='z')T[N++]=c;
  memset(F,0,sizeof(F));
  for(int i=M-1;i>=0;i--)
    for(int j=N-1;j>=0;j--)
      if(S[i]==T[j])
        F[i][j]=(F[i+1][j+1]+F[i][j+1]+1)%Mod;
      else
        F[i][j]=F[i][j+1];
  long long Ans=0;
  for(int i=0;i<M;i++)Ans=(Ans+F[i][0])%Mod;
  cout<<Ans<<endl;
  return 0;
}