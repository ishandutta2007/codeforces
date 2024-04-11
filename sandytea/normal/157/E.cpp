//program 157E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int Mod=1000000007;

int F[101][2501];

void DP()
{
  memset(F,0,sizeof(F));F[0][0]=1;
  for(int i=1;i<=100;i++)
    for(int j=0;j<=i*25;j++)
      for(int k=0;k<26&&k<=j;k++)
        F[i][j]=(F[i][j]+F[i-1][j-k])%Mod;
}

int main()
{
  DP();int Test;cin>>Test;
  while(Test--)
    {
      string S;cin>>S;int N=S.size();
      int Sum=0;for(int i=0;i<N;i++)Sum+=S[i]-97;
      cout<<(F[N][Sum]+Mod-1)%Mod<<endl;
    }
  return 0;
}