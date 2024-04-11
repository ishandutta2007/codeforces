//program 120E

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
  int Test;cin>>Test;
  while(Test--){int N;cin>>N;cout<<((N&1)^1)<<endl;}
  return 0;
}