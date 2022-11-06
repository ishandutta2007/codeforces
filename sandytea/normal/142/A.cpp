//program 142A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long N;cin>>N;
  long long Min=1000000000000000000LL,Max=0;
  for(long long i=1;i*i*i<=N;i++)
    if(N%i==0)
      for(long long j=i;i*j*j<=N;j++)
        if(N%(i*j)==0)
          {
            long long k=N/(i*j),V;
            V=(i+1)*(j+2)*(k+2);
            Min=min(Min,V);Max=max(Max,V);
            V=(i+2)*(j+1)*(k+2);
            Min=min(Min,V);Max=max(Max,V);
            V=(i+2)*(j+2)*(k+1);
            Min=min(Min,V);Max=max(Max,V);
          }
  cout<<Min-N<<' '<<Max-N<<endl;
  return 0;
};