//program 150D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int N,P[160];
string S;
int F[160][160],G[160][160],H[160][160][160];

int Calc_F(int L,int R);
int Calc_G(int L,int R);
int Calc_H(int L,int R,int M);

int Calc_F(int L,int R)
{
  if(L>R)return 0;
  if(F[L][R]!=-1)return F[L][R];
  F[L][R]=Calc_G(L,R);
  for(int i=L;i<=R;i++)F[L][R]=max(F[L][R],Calc_F(L,i-1)+Calc_F(i+1,R));
  return F[L][R];
}

int Calc_G(int L,int R)
{
  if(L>R)return 0;
  if(G[L][R]!=-1)return G[L][R];
  G[L][R]=-inf;
  for(int i=0;i<=R-L;i++)
    if(P[i]>=0)G[L][R]=max(G[L][R],Calc_H(L,R,i+1)+P[i]);
  return G[L][R];
}

int Calc_H(int L,int R,int M)
{
  if(L>R)return 0;
  if(M>R-L+1)return -inf;
  if(H[L][R][M]!=-1)return H[L][R][M];
  if(!M)return Calc_G(L,R);
  H[L][R][M]=-inf;
  if(M==1)
    {
      for(int i=L;i<=R;i++)H[L][R][M]=max(H[L][R][M],Calc_G(L,i-1)+Calc_G(i+1,R));
      return H[L][R][M];
    }
  for(int i=L+1;i<=R;i++)H[L][R][M]=max(H[L][R][M],Calc_G(L,i-1)+Calc_H(i,R,M));
  for(int i=L;i<R;i++)H[L][R][M]=max(H[L][R][M],Calc_G(i+1,R)+Calc_H(L,i,M));
  if(S[L]==S[R]&&M>=2)H[L][R][M]=max(H[L][R][M],Calc_H(L+1,R-1,M-2));
  return H[L][R][M];
}

int main()
{
  cin>>N;for(int i=0;i<N;i++)cin>>P[i];cin>>S;
  for(int i=0;i<N;i++)for(int j=i;j<N;j++)F[i][j]=G[i][j]=-1;
  for(int i=0;i<N;i++)for(int j=i;j<N;j++)for(int k=0;k<=N;k++)H[i][j][k]=-1;
  cout<<Calc_F(0,N-1)<<endl;
  return 0;
}