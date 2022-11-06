//program 112B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,X,Y;cin>>N>>X>>Y;
  cout<<(((X!=N/2&&X!=N/2+1)||(Y!=N/2&&Y!=N/2+1))?"YES":"NO")<<endl;
  return 0;
}