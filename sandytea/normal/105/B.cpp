//program 105B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

double A,Ans=0;
double X[8],Y[8];

double Solve(int N)
{
  double Sum=0;
  for(int i=0;i<(1<<N);i++)
    {
      double P=1;int Count=0;double B=0;
      for(int j=0;j<N;j++)
        if(i&(1<<j))
          {P*=Y[j]/100;Count++;}
        else
          {P*=1-Y[j]/100;B+=X[j];}
      if(Count>N/2)
        Sum+=P;
      else
        Sum+=P*A/(A+B);
    }
  return Sum;
}

void DFS(int V,int N,int Rest)
{
  if(V==N){Ans=max(Ans,Solve(N));return;}
  double Tmp=Y[V];
  for(int i=0;i<=Rest;i++)
    {
      DFS(V+1,N,Rest-i);
      Y[V]+=10;if(Y[V]>100)break;
    }
  Y[V]=Tmp;
}

int main()
{
  int N,M;cin>>N>>M>>A;
  for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
  DFS(0,N,M);
  printf("%0.10lf\n",Ans);
  return 0;
}