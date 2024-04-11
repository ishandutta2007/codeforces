#include <cstdio>
#include <algorithm>
using namespace std;
long long n,b,cur,ex;
long long ans;
long long des(long long n,long long b)
{
	long long ans=n/b;
	for (cur=b;n/cur>=b;)
	{
		cur*=b;
		ans+=n/cur;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld",&n,&b);
	ans=1e18;
	for (long long i=2;b/i>=i;i++)
		if (b%i==0)
		{
			ex=0;
			while (b%i==0)
			{
				ex++;
				b/=i;
			}
			ans=min(ans,des(n,i)/ex);
		}
	if (b!=1)
		ans=min(ans,des(n,b));
	printf("%lld\n",ans);
	return 0;
}