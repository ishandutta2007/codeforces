#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
long long n,m;
inline long long highbit(long long x)
{
	long long last=0;
	while(x&-x)
	{
		last=x&-x;
		x-=last;
	}
	return last;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	if(m==1)printf("%lld\n",n);
	else printf("%lld\n",(highbit(n)<<1)-1);
	return 0;
}