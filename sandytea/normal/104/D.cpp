//program 104D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool Check(long long N,long long M,long long X)
{
  if(X>N)return true;
  if(M<=N/2)return !(X&1)&&(X>N-M*2);
  return !(X&1)||(X>(N-M)*2);
}

int main()
{
  long long N,M,Query;cin>>N>>M>>Query;
  if(!M){while(Query--)putchar('.');putchar('\n');return 0;}
  if(N&1){N--;M--;}
  while(Query--)
    {
      long long X;cin>>X;
      putchar(Check(N,M,X)?'X':'.');
    }
  putchar('\n');
  return 0;
}