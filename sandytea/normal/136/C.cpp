//program 136C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A[100000];

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)scanf("%d",&A[i]);
  sort(A,A+N);
  if(A[N-1]==1)if(N>1)A[N-2]=2;else putchar('2');
  if(N>1||A[N-1]!=1)
    {
      putchar('1');
      for(int i=0;i<N-1;i++)printf(" %d",A[i]);
    }
  putchar('\n');
  return 0;
}