#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int T;
int n;
int a[N];
int rem(int n)
{
	if (n<=1)
		return n^1;
	return (1<<32-__builtin_clz(n-1))-n;
}
int fd(int v)
{
	int l=0,r=n;
	while (l<r)
	{
		int mid=(l+r+1)>>1;
		if (a[mid]<=v)
			l=mid;
		else
			r=mid-1;
	}
	return r;
}
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n+2;i++)
		a[i]=0;
	for (int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		a[v]++;
	}
	for (int i=1;i<=n+2;i++)
		a[i]+=a[i-1];
	int ans=2+rem(n);
	for (int i=1;i<2*n;i<<=1)
	{
		int x=fd(i);
		for (int j=1;j<2*n;j<<=1)
		{
			int y=fd(a[x]+j);
			if (x==y)
				y++;
			ans=min(ans,rem(a[x])+rem(a[y]-a[x])+rem(n-a[y]));
		}
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
	return 0;
}