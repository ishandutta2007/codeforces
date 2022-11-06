//program 108D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

double C(int M,int N)
{
  double Sum=0;
  for(int i=0;i<N;i++)Sum+=log(M-i)-log(i+1);
  return Sum;
}

int main()
{
  int M,N,K;cin>>M>>N>>K;M--;K--;
  int C1=-1,C2=0;
  for(int i=0;i<N;i++){int X;cin>>X;C1+=X;if(i!=K)C2+=X;}
  if(M>C1)
    cout<<-1<<endl;
  else if(M>C2)
    cout<<1<<endl;
  else
    printf("%0.10lf\n",1-exp(C(C2,M)-C(C1,M)));
  return 0;
}