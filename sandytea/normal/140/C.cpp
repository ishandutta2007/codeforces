//program 140C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int Data[100000],X[100000],Y[100000],Ans[3][33333];

int main()
{
  cin>>N;for(int i=0;i<N;i++)cin>>Data[i];
  sort(Data,Data+N);
  int M=0;
  for(int i=0;i<N;i++,M++)
    {
      X[M]=Data[i];Y[M]=1;
      while(i+1<N&&Data[i+1]==Data[i]){i++;Y[M]++;}
    }
  int Left=0,Right=N/3;
  while(Left<Right)
    {
      int Mid=(Left+Right+1)/2,Sum=0;
      for(int i=0;i<N;i++)Sum+=min(Y[i],Mid);
      if(Sum>=Mid*3)Left=Mid;else Right=Mid-1;
    }
  int P=2,Q=0;
  for(int i=0;i<M;i++)
    for(int j=0;j<min(Y[i],Left);j++)
      {
        if(P>=0)Ans[P][Q]=X[i];
        Q++;if(Q==Left){P--;Q=0;}
      }
  cout<<Left<<endl;
  for(int i=0;i<Left;i++)printf("%d %d %d\n",Ans[0][i],Ans[1][i],Ans[2][i]);
  return 0;
}