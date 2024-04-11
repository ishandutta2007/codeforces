#include <cstdio>
using namespace std;
int t;
long long x,y;
void solve()
{
	scanf("%lld%lld",&x,&y);
	if (y<x)
	{
		printf("%lld\n",x+y);
		return;
	}
	if (y==x)
	{
		printf("%lld\n",x);
		return;
	}
	if (y>x)
	{
		printf("%lld\n",y-y%x/2);
		return;
	}
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}