//program 111D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int Mod=1000000007;

long long F[1001][1001];
long long Fac[1000001],Fac2[1000001];

long long Pow(long long A,long long P)
{
  if(!P)return 1;
  long long T=Pow(A,P/2);T=T*T%Mod;
  if(P&1)T=T*A%Mod;
  return T;
}

long long C(long long M,long long N)
{
  return (N>=0&&N<=M)?(Fac[M]*Fac2[N]%Mod*Fac2[M-N]%Mod):0;
}

long long Select(int K,int A,int B)
{
  return C(K,A)*C(A,B)%Mod*C(K-A,A-B)%Mod;
}

int main()
{
  int M,N,K;cin>>M>>N>>K;
  long long Ans;
  if(N==1)
    cout<<Pow(K,M)<<endl;
  else
    {
      Fac[0]=1;Fac2[0]=1;
      for(int i=1;i<=K;i++){Fac[i]=Fac[i-1]*i%Mod;Fac2[i]=Pow(Fac[i],Mod-2);}
      memset(F,0,sizeof(F));F[0][0]=1;
      for(int i=1;i<=M;i++)for(int j=1;j<=i;j++)F[i][j]=(F[i-1][j-1]+F[i-1][j])*j%Mod;
      long long Ans=0;
      for(int i=1;i<=M&&i<=K;i++)
        for(int j=0;j<=i;j++)
          Ans=(Ans+Select(K,i,j)*Pow(F[M][i],2)%Mod*Pow(j,M*(N-2)))%Mod;
      cout<<Ans<<endl;
    }
  return 0;
}