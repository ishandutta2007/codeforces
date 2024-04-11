//program 169D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Data
{
  int Weight,Speed,Number;
};

bool operator <(Data A,Data B)
{
  return (A.Weight==B.Weight)?(A.Speed<B.Speed):(A.Weight<B.Weight);
}

int N,M,H;
int List[100000];
Data A[100000];

bool Check(double T)
{
  int P=1;
  for(int i=0;i<N;i++)
    {
      if(T*A[i].Speed>=P*H){List[P-1]=A[i].Number;P++;}
      if(P>M)return true;
    }
  return false;
}

int main()
{
  scanf("%d%d%d",&N,&M,&H);
  for(int i=0;i<N;i++)scanf("%d",&A[i].Weight);
  for(int i=0;i<N;i++)scanf("%d",&A[i].Speed);
  for(int i=0;i<N;i++)A[i].Number=i+1;
  sort(A,A+N);
  double Left=0,Right=1000000000;
  for(int i=0;i<150;i++)
    {
      double Mid=(Left+Right)/2;
      if(Check(Mid))Right=Mid;else Left=Mid;
    }
  Check(Right);
  for(int i=0;i<M;i++)
    {
      printf("%d",List[i]);
      putchar((i==M-1)?'\n':' ');
    }
  return 0;
}