//program 124A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,A,B;cin>>N>>A>>B;
  cout<<min(N-A,B+1)<<endl;
  return 0;
}