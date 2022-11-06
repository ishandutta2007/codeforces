//program 107D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Matrix
{
  int Size;
  int M[200][200];
};

const int Mod=12345;

int GCD(int A,int B)
{
  return B?GCD(B,A%B):A;
}

Matrix NewMatrix(int N)
{
  Matrix T;T.Size=N;
  memset(T.M,0,sizeof(T.M));
  return T;
}

Matrix Mult(Matrix A,Matrix B)
{
  Matrix T=NewMatrix(A.Size);
  for(int k=0;k<T.Size;k++)
    for(int i=0;i<T.Size;i++)
      for(int j=0;j<T.Size;j++)
        T.M[i][j]=(T.M[i][j]+A.M[i][k]*B.M[k][j])%Mod;
  return T;
}

int main()
{
  long long K;int M;cin>>K>>M;
  if(!K){cout<<1<<endl;return 0;}
  vector<int> A[26],Data[26];
  while(M--)
    {
      char c=getchar();while(c<'A'||c>'Z')c=getchar();
      int X;cin>>X;A[c-65].push_back(X);
    }
  int Total=0,Size[26];
  for(int i=0;i<26;i++)
    if(A[i].size())
      {
        int T=1;
        for(int j=0;j<A[i].size();j++)
          T=T*A[i][j]/GCD(T,A[i][j]);
        Size[Total]=T;Data[Total]=A[i];Total++;
      }
  if(!Total){cout<<0<<endl;return 0;}
  int Weight[26];Weight[Total-1]=1;for(int i=Total-1;i;i--)Weight[i-1]=Weight[i]*Size[i];
  int N=Weight[0]*Size[0];
  Matrix G=NewMatrix(N);
  for(int i=0;i<N;i++)
    {
      int Tmp=i,A[26];
      for(int j=0;j<Total;j++){A[j]=Tmp/Weight[j];Tmp%=Weight[j];}
      for(int j=0;j<Total;j++)
        {
          int B[26];for(int k=0;k<Total;k++)B[k]=A[k];B[j]=(B[j]+1)%Size[j];
          int Number=0;for(int k=0;k<Total;k++)Number+=B[k]*Weight[k];
          G.M[Number][i]++;
        }
    }
  Matrix T=NewMatrix(N);for(int i=0;i<N;i++)T.M[i][i]=1;
  long long P=1;while(P*2<=K)P*=2;
  while(P){T=Mult(T,T);if(K&P)T=Mult(T,G);P/=2;}
  int Ans=0;
  for(int i=0;i<N;i++)
    {
      int Tmp=i,A[26];for(int j=0;j<Total;j++){A[j]=Tmp/Weight[j];Tmp%=Weight[j];}
      bool Flag=true;
      for(int j=0;Flag&&j<Total;j++)
        {
          Flag=false;
          for(int k=0;!Flag&&k<Data[j].size();k++)Flag=!(A[j]%Data[j][k]);
        }
      if(Flag)Ans=(Ans+T.M[i][0])%Mod;
    }
  cout<<Ans<<endl;
  return 0;
}