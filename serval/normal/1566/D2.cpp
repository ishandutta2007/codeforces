#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int N=305*305;

int T;

int n,m;
int a[N],p[N];
long long ans;

map <int,int> tot;
map <int,set<int> > v;

void solve()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		tot[a[i]]++;
		v[a[i]].insert(i);
	}
	sort(a+1,a+n*m+1);
	ans=0;
	int cv=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cv=(i-1)*m+j;
			int cur=a[cv];
			int sz=tot[cur];
			if (j+sz-1>m)
				sz=m-j+1;
			for (int k=sz;k;k--)
			{
				set<int>::iterator it=v[cur].begin();
				p[cv+k-1]=*it;
				v[cur].erase(it);
				tot[cur]--;
			}
			j+=sz-1;
		}
	for (int i=1;i<=n;i++)
	{
		int o=(i-1)*m;
		for (int j=1;j<=m;j++)
			for (int k=1;k<j;k++)
				if (p[o+k]<p[o+j])
					ans++;
	}
	printf("%lld\n",ans);
}

int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}