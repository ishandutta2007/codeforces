//program 92A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,M,P=1;cin>>N>>M;
  while(M>=P){M-=P;P++;if(P>N)P=1;}
  cout<<M<<endl;
  return 0;
}