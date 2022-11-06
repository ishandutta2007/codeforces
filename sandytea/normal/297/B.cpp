//program 297-B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int Get()
{
  char c;
  while(c=getchar(),c<'0'||c>'9');
  int X=0;
  while(c>='0'&&c<='9')
    {
      X=X*10+c-48;
      c=getchar();
    }
  return X;
}

void Output(int X)
{
  int Len=0,Data[10];
  while(X)
    {
      Data[Len++]=X%10;
      X/=10;
    }
  if(!Len)
    Data[Len++]=0;
  while(Len--)
    putchar(Data[Len]+48);
  putchar('\n');
}

int main()
{
  int M=Get(),N=Get(),K=Get();
  multiset<int> A,B;
  for(int i=0;i<M;i++)
    A.insert(Get());
  for(int i=0;i<N;i++)
    {
      int X=Get();
      if(A.find(X)!=A.end())
        A.erase(A.find(X));
      else
        B.insert(X);
    }
  M=N=0;
  static int X[100000],Y[100000];
  for(multiset<int>::iterator P=A.begin();P!=A.end();P++)
    X[M++]=*P;
  for(multiset<int>::iterator P=B.begin();P!=B.end();P++)
    Y[N++]=*P;
  int P=M-1,Q=N-1;
  while(P>=0&&Q>=0)
    {
      if(X[P]>Y[Q])
        {
          printf("YES\n");
          return 0;
        }
      P--;
      Q--;
    }
  if(P>=0)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}