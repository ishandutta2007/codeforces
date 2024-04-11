#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 10000000000000000
using namespace std;
long long m,n;
long long calc(long long x)
{
	long long cnt=0;
	for(long long i=2;i*i*i<=x;i++)
	  cnt+=x/(i*i*i);
	  return cnt;
}
int main()
{
	scanf("%I64d",&m);
	long long lb=1,ub=INF;
	for(int i=0;i<200;i++)
	{
		long long mid=(lb+ub)/2;
		if(calc(mid)<m) lb=mid; else ub=mid;
	}
	if(calc(ub)>m) printf("-1"); else printf("%I64d\n",ub);
	return 0;
}