//program 139A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,A[7];
  cin>>N>>A[0]>>A[1]>>A[2]>>A[3]>>A[4]>>A[5]>>A[6];
  int P=0;
  while(N>A[P%7])N-=A[(P++)%7];
  cout<<P%7+1<<endl;
  return 0;
}