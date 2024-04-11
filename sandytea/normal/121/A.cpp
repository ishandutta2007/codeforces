//program 121A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

long long Count(long long L1,long long R1,long long L2,long long R2)
{
  long long L=max(L1,L2),R=min(R1,R2);
  return (L<=R)?(R-L+1):0;
}

int main()
{
  int L,R;cin>>L>>R;
  int Total=1;long long Data[2000];memset(Data,0,sizeof(Data));
  for(int i=1;i<=9;i++)
    for(int j=0;j<(1<<i);j++)
      {for(int k=0;k<i;k++)Data[Total]=Data[Total]*10+((j&(1<<k))?4:7);Total++;}
  sort(Data,Data+Total);Data[Total]=4444444444LL;
  long long Ans=0;
  for(int i=0;i<Total;i++)Ans+=Count(L,R,Data[i]+1,Data[i+1])*Data[i+1];
  cout<<Ans<<endl;
  return 0;
}