//program 109B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

long long Cross(long long L1,long long R1,long long L2,long long R2)
{
  if(max(L1,L2)>min(R1,R2))return 0;
  return min(R1,R2)-max(L1,L2)+1;
}

int main()
{
  int Total=0,Lucky[1024];
  for(int i=1;i<=9;i++)
    for(int j=0;j<(1<<i);j++)
      {
        int S=0;
        for(int k=0;k<i;k++)
          S=S*10+((j&(1<<k))?4:7);
        Lucky[Total++]=S;
      }
  Lucky[Total++]=0;Lucky[Total++]=1000000001;
  sort(Lucky,Lucky+Total);
  int L1,R1,L2,R2,K;cin>>L1>>R1>>L2>>R2>>K;
  long long Count=0;
  for(int Left=1,Right=K;Right<Total-1;Left++,Right++)
    {
      Count+=Cross(L1,R1,Lucky[Left-1]+1,Lucky[Left])*Cross(L2,R2,Lucky[Right],Lucky[Right+1]-1);
      Count+=Cross(L2,R2,Lucky[Left-1]+1,Lucky[Left])*Cross(L1,R1,Lucky[Right],Lucky[Right+1]-1);
    }
  if(K==1)
    for(int i=1;i<Total-1;i++)
      if(Lucky[i]>=max(L1,L2)&&Lucky[i]<=min(R1,R2))
        Count--;
  double Ans=double(Count)/(R1-L1+1)/(R2-L2+1);
  printf("%0.10lf\n",Ans);
  return 0;
}