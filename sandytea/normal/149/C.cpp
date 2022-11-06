//program 149C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct DataType
{
  int X,Y;
};

DataType A[100000];
int X[50000],Y[50000];

bool Cmp(DataType A,DataType B)
{
  return A.X<B.X;
}

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int x=c-48;while(c=getchar(),c>='0'&&c<='9')x=x*10+c-48;
  return x;
}

int Output(int X)
{
  int Len=0,Data[20];
  while(X){Data[Len++]=X%10;X/=10;}
  if(!Len)Data[Len++]=0;
  while(Len--)putchar(Data[Len]+48);
}

int main()
{
  int N=GetNumber();
  for(int i=0;i<N;i++){A[i].X=GetNumber();A[i].Y=i+1;}
  sort(A,A+N,Cmp);
  int P=0,Q=0;
  for(int i=0;i<N;i++)if(i%2)X[P++]=A[i].Y;else Y[Q++]=A[i].Y;
  Output(P);putchar('\n');
  for(int i=0;i<P;i++){Output(X[i]);putchar((i==P-1)?'\n':' ');}
  Output(Q);putchar('\n');
  for(int i=0;i<Q;i++){Output(Y[i]);putchar((i==Q-1)?'\n':' ');}
  return 0;
}