//program 258-B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int Mod=1000000007;

long long A[10];
long long Sum;
int Count[10];

int Solve(int M,int Count)
{
  static int A[10];
  for(int i=0;i<10;i++)
    {
      A[i]=M%10;
      M/=10;
    }
  static int DP[11][2][10];
  memset(DP,0,sizeof(DP));
  DP[0][0][Count]=DP[0][1][Count]=1;
  for(int i=0;i<10;i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<=Count;k++)
        for(int D=0;D<10;D++)
          {
            if(!j&&D>A[i])
              continue;
            int New_k=k+(D==4||D==7);
            if(New_k<=Count)
              DP[i+1][j][k]+=DP[i][j||(D<A[i])][New_k];
          }
  return DP[10][0][0];
}

long long P(long long N,int M)
{
  long long S=1;
  for(int i=0;i<M;i++)
    S=S*(N-i)%Mod;
  return S;
}

void Check()
{
  long long Ans=1;
  for(int i=0;i<10;i++)
    Ans=Ans*P(A[i],Count[i])%Mod;
  Sum=(Sum+Ans)%Mod;
}

void Search(int Depth,int Current,int Max)
{
  if(Depth==6)
    {
      Check();
      return;
    }
  for(int i=0;i<=Max-Current;i++)
    {
      Count[i]++;
      Search(Depth+1,Current+i,Max);
      Count[i]--;
    }
}

int main()
{
  int M;
  scanf("%d",&M);
  for(int i=0;i<=9;i++)
    A[i]=Solve(M,i);
  A[0]--;
  long long Ans=0;
  for(int i=1;i<=9;i++)
    {
      Sum=0;
      memset(Count,0,sizeof(Count));
      Search(0,0,i-1);
      Ans=(Ans+A[i]*Sum)%Mod;
    }
  cout<<Ans<<endl;
  return 0;
}