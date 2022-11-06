//program 119B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const double inf=1000000000;

int main()
{
  int N,K,Len;cin>>N>>K;Len=N/K;
  double A[100];for(int i=0;i<N;i++)cin>>A[i];
  int M;cin>>M;
  double Min=inf,Max=-inf;int Count=0;
  bool Flag[100];memset(Flag,0,sizeof(Flag));
  for(int i=0;i<M;i++)
    {
      double Sum=0;
      for(int j=0;j<Len;j++)
        {
          int X;cin>>X;Sum+=A[--X];
          if(!Flag[X]){Count++;Flag[X]=true;}
        }
      Min=min(Min,Sum);Max=max(Max,Sum);
    }
  if(Count<K*Len)
    {
      double Data[100];for(int i=M=0;i<N;i++)if(!Flag[i])Data[M++]=A[i];sort(Data,Data+M);
      double Sum;
      Sum=0;for(int i=0;i<Len;i++)Sum+=Data[i];Min=min(Min,Sum);
      Sum=0;for(int i=M-Len;i<M;i++)Sum+=Data[i];Max=max(Max,Sum);
    }
  printf("%0.10lf %0.10lf\n",Min/Len,Max/Len);
  return 0;
}