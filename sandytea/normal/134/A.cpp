//program 134A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A[200000],Ans[200000];

int main()
{
  int N;cin>>N;for(int i=0;i<N;i++)scanf("%d",&A[i]);
  int Sum=0;for(int i=0;i<N;i++)Sum+=A[i];
  int Total=0;for(int i=0;i<N;i++)if(A[i]*N==Sum)Ans[Total++]=i+1;
  cout<<Total<<endl;
  for(int i=0;i<Total;i++)
    {
      printf("%d",Ans[i]);
      putchar((i==Total-1)?'\n':' ');
    }
  return 0;
}