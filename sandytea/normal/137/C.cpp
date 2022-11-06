//program 137C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Data
{
  int x,y;
};

Data A[100000];

int Cmp(Data A,Data B)
{
  return A.x<B.x;
}

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)scanf("%d%d",&A[i].x,&A[i].y);
  sort(A,A+N,Cmp);
  int Max=0,Ans=0;
  for(int i=0;i<N;i++)if(Max>A[i].y)Ans++;else Max=A[i].y;
  cout<<Ans<<endl;
  return 0;
}