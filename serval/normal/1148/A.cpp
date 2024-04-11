#include <cstdio>
#include <algorithm>
using namespace std;
long long a,b,c;
long long ans,cur;
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	ans=2ll*c;
	cur=min(a,b);
	ans+=2ll*cur;
	a-=cur;
	b-=cur;
	if (b)
		ans++;
	if (a)
		ans++;
	printf("%lld\n",ans);
	return 0;
}