//program 146E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int P=1000000007;

long long Data[100000],A[100000],Fac[100001];
long long F[1023][1023];

bool Lucky(int X)
{
  if(!X)return true;
  if(X%10!=4&&X%10!=7)return false;
  return Lucky(X/10);
}

long long Pow(long long A,long long B)
{
  if(!B)return 1;
  long long Tmp=Pow(A,B/2);
  Tmp=Tmp*Tmp%P;
  if(B%2)Tmp=Tmp*A%P;
  return Tmp;
}

long long Calc(long long N,long long K)
{
  long long S=Fac[N];
  S=S*Pow(Fac[K],P-2)%P;
  S=S*Pow(Fac[N-K],P-2)%P;
  return S;
}

int main()
{
  int M,K;cin>>M>>K;
  int Total=0,Count=0;
  while(M--)
    {
      int X;scanf("%d",&X);
      if(Lucky(X))Data[Total++]=X;else Count++;
    }
  sort(Data,Data+Total);int N=0;
  for(int i=0;i<Total;i++)
    {
      int Len=1;
      while(i+1<Total&&Data[i]==Data[i+1]){i++;Len++;}
      A[N++]=Len;
    }
  memset(F,0,sizeof(F));
  for(int i=0;i<=N;i++)F[i][0]=1;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=i;j++)
      F[i][j]=(A[i-1]*F[i-1][j-1]+F[i-1][j])%P;
  Fac[0]=1;
  for(long long i=1;i<=Count;i++)Fac[i]=Fac[i-1]*i%P;
  long long Ans=0;
  for(int i=max(K-Count,0);i<=min(N,K);i++)
    Ans=(Ans+F[N][i]*Calc(Count,K-i))%P;
  cout<<Ans<<endl;
  return 0;
}