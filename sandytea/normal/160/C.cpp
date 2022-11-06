//program 160C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A[100000];

int main()
{
  int N;long long K;cin>>N>>K;K--;
  for(int i=0;i<N;i++)cin>>A[i];sort(A,A+N);
  int P=A[K/N],X=0;while(A[X]!=P){X++;K-=N;}
  int Y=1;while(X+Y<N&&A[X+Y]==A[X])Y++;
  int Q=A[K/Y];cout<<P<<' '<<Q<<endl;
  return 0;
}