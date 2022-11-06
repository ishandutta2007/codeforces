//program 158A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,K;cin>>N>>K;
  int A[100];for(int i=0;i<N;i++)cin>>A[i];
  if(A[K-1]<=0)
    {
      int P=K-2;
      while(P>=0&&A[P]<=0)P--;
      cout<<P+1<<endl;
    }
  else
    {
      int P=K;
      while(P<N&&A[P]==A[P-1])P++;
      cout<<P<<endl;
    }
  return 0;
}