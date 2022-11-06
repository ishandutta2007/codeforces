//program 144A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,A[100];cin>>N;
  for(int i=0;i<N;i++)cin>>A[i];
  int P=0,Q=N-1;
  for(int i=0;i<N;i++)
    {
      if(A[i]>A[P])P=i;
      if(A[i]<=A[Q])Q=i;
    }
  int Ans=P+N-1-Q;
  cout<<((Ans<N)?Ans:(Ans-1))<<endl;
  return 0;
}