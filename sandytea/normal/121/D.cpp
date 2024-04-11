//program 121D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct VeryBigNumber
{
  long long A,B;
};

const long long Q=(1LL<<50)-1,High=(1LL<<50);

int N,P1,P2;
VeryBigNumber K,MinLength,S1,S2,Zero;
VeryBigNumber X[100000],Y[100000],S[1000000];

VeryBigNumber operator +(VeryBigNumber X,VeryBigNumber Y)
{
  VeryBigNumber Result;
  Result.A=X.A+Y.A;Result.B=X.B+Y.B;
  Result.A+=Result.B>>50;Result.B&=Q;
  return Result;
};

VeryBigNumber operator -(VeryBigNumber X,VeryBigNumber Y)
{
  VeryBigNumber Result=X;
  if(Result.B<Y.B){Result.B|=High;Result.A--;}
  Result.A-=Y.A;Result.B-=Y.B;
  return Result;
};

VeryBigNumber operator *(VeryBigNumber X,long long Y)
{
  if(Y==0)return Zero;if(Y==1)return X;
  VeryBigNumber Result=X*(Y/2);
  Result=Result+Result;
  if(Y&1)Result=Result+X;
  return Result;
};

bool operator <(VeryBigNumber X,VeryBigNumber Y)
{
  return (X.A<Y.A)||(X.A==Y.A&&X.B<Y.B);
}

VeryBigNumber Change(long long X)
{
  VeryBigNumber T;
  T.A=X>>50;T.B=X&Q;return T;
}

VeryBigNumber GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  long long X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return Change(X);
}

bool OK(VeryBigNumber L,VeryBigNumber R)
{
  if(MinLength<R-L)return false;
  while(P1<N&&X[P1]<L)S1=S1-X[P1++];
  while(P2<N&&Y[P2]<R)S2=S2+Y[P2++];
  VeryBigNumber T=S1+R*P2-S2-L*(N-P1);
  return T<K;
}

int main()
{
  cin>>N;K=GetNumber();
  K.B++;if(K.B==High){K.A++;K.B=0;}
  MinLength.A=MinLength.B=Q;Zero.A=Zero.B=0;
  for(int i=0;i<N;i++)
    {
      X[i]=GetNumber();Y[i]=GetNumber();
      MinLength=min(MinLength,Y[i]-X[i]);
    }
  sort(X,X+N);sort(Y,Y+N);
  int M=0;
  for(int i=1;i<=18;i++)
    for(int j=0;j<(1<<i);j++)
      {
        long long T=0;
        for(int k=0;k<i;k++)T=T*10+((j&(1<<k))?4:7);
        S[M++]=Change(T);
      }
  sort(S,S+M);
  int Ans=P1=P2=0;S1=S2=Zero;
  while(P1<N&&!X[P1].A&&X[P1].B<4)P1++;
  for(int i=P1;i<N;i++)S1=S1+X[i];
  for(int L=0,R=0;L<M;L++,R=max(L,R)){while(R<M&&OK(S[L],S[R]))R++;Ans=max(Ans,R-L);}
  cout<<Ans<<endl;
  return 0;
}