#include <cstdio>
using namespace std;
int q;
long long l,r;
long long ans,a,b;
int main()
{
	scanf("%d",&q);
	while (q--)
	{
		scanf("%lld%lld",&l,&r);
		ans=0;
		a=l+(l&1);
		b=r-(r&1);
		ans+=(a+b)/2*((b-a)/2+1);
		a=l+((l&1)^1);
		b=r-((r&1)^1);
		ans-=(a+b)/2*((b-a)/2+1);
		printf("%lld\n",ans);
	}
	return 0;
}