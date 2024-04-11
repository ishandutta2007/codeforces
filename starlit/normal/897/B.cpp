#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p;
long long len(long long x)
{
	long long i;
	for(i=1;i<=x;i*=10);
	return i;
}
int ni(long long x)
{
	int ret=0;
	long long now=len(x)/10;
	while(x)
	{
		ret+=x%10*now;
		now/=10,x/=10;
	}return ret;
}
long long i,ans;
int main()
{
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
	ans=(ans+i*len(i)+ni(i))%p;
	printf("%lld",ans);
}