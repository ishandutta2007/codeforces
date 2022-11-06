//program 108B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  int A[100000];for(int i=0;i<N;i++)cin>>A[i];
  sort(A,A+N);
  bool Ans=false;
  for(int i=1;!Ans&&i<N;i++)Ans=(A[i]>A[i-1]&&A[i]<A[i-1]*2);
  cout<<(Ans?"YES":"NO")<<endl;
  return 0;
}