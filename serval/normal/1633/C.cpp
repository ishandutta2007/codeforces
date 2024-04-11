#include <cstdio>
#include <algorithm>
using namespace std;
long long hc,dc,hm,dm;
long long k,w,a;
bool solve()
{
	scanf("%lld%lld%lld%lld",&hc,&dc,&hm,&dm);
	scanf("%lld%lld%lld",&k,&w,&a);
	for (int i=0;i<=k;i++)
	{
		long long hcc=hc+a*i,dcc=dc+w*(k-i);
		if ((hm+dcc-1)/dcc<=(hcc+dm-1)/dm)
			return 1;
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		printf(solve()?"YES\n":"NO\n");
	return 0;
}