#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int N=3e5+5;
int n,m,lim;
int a[N],b[N];
int c[N],p[N],pos[N],g[N],gc;
int cnt,ts;
long long ans;
map <pair<int,int>,int> mp;
void chk(int u,int v)
{
	if (u==v)
		return;
	if (1ll*(c[u]+c[v])*(b[u]+b[v])>ans)
		if (mp[make_pair(b[u],b[v])]!=ts)
			ans=1ll*(c[u]+c[v])*(b[u]+b[v]);
}
bool cmp(int x,int y)
{
	if (c[x]!=c[y])
		return c[x]<c[y];
	return b[x]>b[y];
}
void solve()
{
	ts++;
	ans=0;
	scanf("%d%d",&n,&m);
	lim=sqrt(n)+1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=c[i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		mp[make_pair(u,v)]=ts;
		mp[make_pair(v,u)]=ts;
	}
	sort(a+1,a+n+1);
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=a[i-1])
		{
			cnt++;
			b[cnt]=a[i];
		}
		c[cnt]++;
	}
	for (int i=1;i<=cnt;i++)
		p[i]=i;
	sort(p+1,p+cnt+1,cmp);
	gc=0;
	for (int i=1;i<=cnt;i++)
		if (c[i]>=lim)
			g[++gc]=i;
	for (int i=1;i<=gc;i++)
		for (int j=1;j<=cnt;j++)
			chk(g[i],j);
	for (int i=1;i<=n;i++)
		pos[i]=0;
	for (int i=cnt;i;i--)
		pos[c[p[i]]]=i;
	for (int i=2;i<=2*lim;i++)
	{
		for (int j=1;j<=cnt;j++)
			if (c[j]<lim&&i-c[j]>0&&i-c[j]<lim)
			{
				int cur=i-c[j];
				int k=pos[cur];
				while (k<=cnt&&c[p[k]]==cur)
				{
					if (p[k]!=j)
						if (mp[make_pair(b[j],b[p[k]])]!=ts)
						{
							chk(j,p[k]);
							break;
						}
					k++;
				}
			}
	}
	printf("%lld\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}