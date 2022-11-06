//program 140E

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int Len[1000000];
long long G[5001][5001];

long long GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int x=c-48;while(c=getchar(),c>='0'&&c<='9')x=x*10+c-48;
  return x;
}

int GCD(int X,int Y)
{
  return (Y)?GCD(Y,X%Y):X;
}


int main()
{
  long long N=GetNumber(),M=GetNumber(),P=GetNumber();
  for(int i=0;i<N;i++)Len[i]=GetNumber();
  memset(G,0,sizeof(G));G[0][0]=1;
  for(int i=1;i<=5000;i++)
    for(int j=1;j<=i&&j<=M;j++)
      G[i][j]=(G[i-1][j-1]+G[i-1][j]*(j-1))%P;
  long long A[5001];A[0]=1;for(int i=0;i<5000;i++)A[i+1]=A[i]*(M-i)%P;
  long long Sum=0,F1[5001];for(int i=1;i<=Len[0];i++)Sum=(Sum+(F1[i]=G[Len[0]][i]*A[i]%P))%P;
  long long Fac[5001];Fac[0]=1;for(int i=1;i<=5000;i++)Fac[i]=Fac[i-1]*i%P;
  for(int i=1;i<N;i++)
    {
      long long F2[5001];
      for(int j=1;j<=Len[i];j++)
        {
          F2[j]=Sum*G[Len[i]][j]%P*A[j]%P;
          if(j<=Len[i-1])F2[j]-=F1[j]*G[Len[i]][j]%P*Fac[j]%P;
          if(F2[j]<0)F2[j]+=P;
        }
      Sum=0;for(int j=1;j<=Len[i];j++)Sum=(Sum+(F1[j]=F2[j]))%P;
    }
  cout<<Sum<<endl;
  return 0;
}