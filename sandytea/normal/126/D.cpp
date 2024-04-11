//program 126D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long S[91];S[0]=1;S[1]=2;
  for(int i=2;i<=90;i++)S[i]=S[i-1]+S[i-2];
  int Test;cin>>Test;
  while(Test--)
    {
      long long X;cin>>X;
      bool A[91];memset(A,0,sizeof(A));
      for(int i=90;i>=0;i--)if(X>=S[i]){A[i]=true;X-=S[i];}
      long long F[91],G[91];F[0]=1;G[0]=0;
      for(int i=1;i<=90;i++)
        {
          F[i]=F[i-1];if(A[i-1])F[i]+=G[i-1];
          if(i==1||A[i-1])
            G[i]=0;
          else if(A[i-2])
            G[i]=G[i-2];
          else
            G[i]=F[i-2]+G[i-2];
        }
      int P=90;while(!A[P])P--;
      cout<<F[P]+G[P]<<endl;
    }
  return 0;
}