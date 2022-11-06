//program 120B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int N,M;cin>>N>>M;
  int A[1001];for(int i=1;i<=N;i++)cin>>A[i];
  while(!A[M])M=M%N+1;cout<<M<<endl;
  return 0;
}