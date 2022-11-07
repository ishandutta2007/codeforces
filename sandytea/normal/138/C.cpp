//program 138C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct DataType
{
  int X,Flag;
  double P;
};

DataType Data[410000];

bool Cmp(DataType A,DataType B)
{
  if(A.X<B.X)return true;
  if(A.X>B.X)return false;
  return A.Flag<B.Flag;
}

int main()
{
  int M,N,T=0;scanf("%d%d",&M,&N);
  for(int i=0;i<M;i++)
    {
      int X,H;double L,R;scanf("%d%d%lf%lf",&X,&H,&L,&R);
      if(L==100)L=99.999;if(R==100)R=99.999;
      Data[T].X=X-H;Data[T].P=log(1-L/100);Data[T++].Flag=-1;
      Data[T].X=X;Data[T].P=-log(1-L/100);Data[T++].Flag=-1;
      Data[T].X=X;Data[T].P=log(1-R/100);Data[T++].Flag=1;
      Data[T].X=X+H;Data[T].P=-log(1-R/100);Data[T++].Flag=1;
    }
  for(int i=0;i<N;i++)
    {
      scanf("%d%lf",&Data[T].X,&Data[T].P);
      Data[T++].Flag=0;
    }
  sort(Data,Data+T,Cmp);
  double Sum=0,Ans=0;
  for(int i=0;i<T;i++)
    if(Data[i].Flag)
      Sum+=Data[i].P;
    else
      Ans+=Data[i].P*exp(Sum);
  cout<<Ans<<endl;
  return 0;
}