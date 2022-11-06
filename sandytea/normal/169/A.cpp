//program 169A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A[2000];

int main()
{
  int N,X,Y;scanf("%d%d%d",&N,&X,&Y);
  for(int i=0;i<N;i++){scanf("%d",&A[i]);A[i]=-A[i];}
  sort(A,A+N);
  printf("%d\n",A[X]-A[X-1]);
  return 0;
}