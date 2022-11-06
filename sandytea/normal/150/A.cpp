//program 150A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long N;cin>>N;
  int M=0;long long A[10000];
  for(long long i=2;N>1&&i*i<=N;i++)
    while(N%i==0){A[M++]=i;N/=i;}
  if(N>1)A[M++]=N;
  if(M<=1)cout<<"1\n0\n";
  else if(M==2)cout<<"2\n";
  else cout<<"1\n"<<A[0]*A[1]<<endl;
  return 0;
}