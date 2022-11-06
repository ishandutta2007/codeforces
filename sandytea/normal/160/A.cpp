//program 160A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  int A[100];for(int i=0;i<N;i++)cin>>A[i];
  int Sum=0;for(int i=0;i<N;i++)Sum+=A[i];
  sort(A,A+N);
  int Ans=0,My=0;while(My*2<=Sum)My+=A[N-(++Ans)];
  cout<<Ans<<endl;
  return 0;
}