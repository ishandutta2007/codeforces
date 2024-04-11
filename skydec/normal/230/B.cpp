#include<stdio.h>
#include<cmath>
using namespace std;
typedef long long LL;
long n;
bool prime(LL k)
{
	for(LL i=2;i*i<=k;i++)
	if(k%i==0)return false;
	return true;
}
int main()
{
	scanf("%ld",&n);
	for(long i=1;i<=n;i++)
	{
		LL t;scanf("%I64d",&t);
		if(t==1)
		{
			printf("NO\n");
		}
		else
		{
			LL j=(LL)sqrt(t);
			if(j*j!=t)printf("NO\n");
			else if(prime(j))printf("YES\n");else printf("NO\n");
		}
	}
	return 0;
}