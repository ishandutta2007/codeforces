#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1005;
int T;
int n;
int k[N],h[N],p[N],st[N],ed[N];
long long ans;
long long f(long long len)
{
	return (1+len)*len/2;
}
bool cmp(int a,int b)
{
	if (st[a]!=st[b])
		return st[a]<st[b];
	return ed[a]<ed[b];
}
void solve()
{
	ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		st[i]=k[i]-h[i]+1;
		ed[i]=k[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int curs=st[p[i]],curt=ed[p[i]];
		int j=i;
		while (curs<=st[p[j]]&&st[p[j]]<=curt&&j<=n)
		{
			curt=max(curt,ed[p[j]]);
			j++;
		}
		ans+=f(curt-curs+1);
		i=j-1;
	}
	printf("%lld\n",ans);
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