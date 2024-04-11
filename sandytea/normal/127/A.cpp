//program 127A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
  int N,K;cin>>N>>K;
  double X[100],Y[100];
  for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
  double Ans=0;
  for(int i=1;i<N;i++)Ans+=sqrt((X[i]-X[i-1])*(X[i]-X[i-1])+(Y[i]-Y[i-1])*(Y[i]-Y[i-1]));
  printf("%0.10lf\n",Ans*K/50);
  return 0;
}