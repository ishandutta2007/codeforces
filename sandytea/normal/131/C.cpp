//program 131C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long M,N,K;cin>>M>>N>>K;
  long long C[31][31];memset(C,0,sizeof(C));
  for(int i=0;i<=30;i++)C[i][0]=1;
  for(int i=1;i<=30;i++)
    for(int j=1;j<=i;j++)
      C[i][j]=C[i-1][j-1]+C[i-1][j];
  long long Ans=0;
  for(int i=4,j=K-4;j;i++,j--)
    if(i<=M&&j<=N)
      Ans+=C[M][i]*C[N][j];
  cout<<Ans<<endl;
  return 0;
}