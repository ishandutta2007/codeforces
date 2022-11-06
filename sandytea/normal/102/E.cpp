//program 102E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool Check(long long A,long long B,long long T1,long long T2)
{
  if(!A&&!B)return !T1&&!T2;
  return !((T1*A+T2*B)%(A*A+B*B))&&!((T2*A-T1*B)%(A*A+B*B));
}

int main()
{
  long long X0,Y0,X1,Y1,X2,Y2;cin>>X0>>Y0>>X1>>Y1>>X2>>Y2;
  cout<<((Check(X2,Y2,X1-X0,Y1-Y0)||Check(X2,Y2,Y1-X0,-X1-Y0)||Check(X2,Y2,-X1-X0,-Y1-Y0)||Check(X2,Y2,-Y1-X0,X1-Y0))?"YES":"NO")<<endl;
  return 0;
}