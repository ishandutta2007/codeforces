//program 128D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A[100000],L[100000];

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)scanf("%d",&A[i]);
  sort(A,A+N);
  int M=0;
  for(int i=0;i<N;i++)
    {
      L[M]=1;
      while(i+1<N&&A[i]==A[i+1]){i++;L[M]++;}
      M++;
    }
  if(A[N-1]!=A[0]+M-1)
    cout<<"NO"<<endl;
  else
    {
      for(int i=0;i+1<M;i++)
        if(L[i+1]<=L[i]&&i+2<M)break;else L[i+1]-=L[i];
      cout<<(L[M-1]?"NO":"YES")<<endl;
    }
  return 0;
}