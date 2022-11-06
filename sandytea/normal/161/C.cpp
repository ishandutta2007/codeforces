//program 161C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Pow[30];

int LCS(int D,int L1,int R1,int L2,int R2)
{
  if(L1>R1||L2>R2)return 0;if(!D)return 1;
  if(L1==L2)return min(R1,R2)-L1+1;
  if(R1==R2)return R1-max(L1,L2)+1;
  if(L1>Pow[D]){L1-=Pow[D];R1-=Pow[D];}
  if(L2>Pow[D]){L2-=Pow[D];R2-=Pow[D];}
  if(R1<Pow[D]&&R2<Pow[D])return LCS(D-1,L1,R1,L2,R2);
  if(R1<Pow[D])return max(LCS(D-1,L1,R1,L2,Pow[D]-1),LCS(D-1,L1,R1,1,R2-Pow[D]));
  if(R2<Pow[D])return max(LCS(D-1,L2,R2,L1,Pow[D]-1),LCS(D-1,L2,R2,1,R1-Pow[D]));
  int X1=LCS(D-1,L1,Pow[D]-1,1,R2-Pow[D]);
  int X2=LCS(D-1,1,R1-Pow[D],L2,Pow[D]-1);
  return max(max(X1,X2),min(R1,R2)-max(L1,L2)+1);
}

int main()
{
  int L1,R1,L2,R2;cin>>L1>>R1>>L2>>R2;
  for(int i=0;i<30;i++)Pow[i]=1<<i;
  cout<<LCS(29,L1,R1,L2,R2)<<endl;
  return 0;
}