#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int N=2e5+5;
const int E=N<<1;

int T;

int n;
int h[N],to[E],nx[E],et;

int par[N],sz[N],leaf[N];

int q[N],ql,qt;

int ans;

void ae(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}

void dfs(int u,int fr=0)
{
	par[u]=fr;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=fr)
			dfs(to[i],u);
}

void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		h[i]=sz[i]=leaf[i]=0;
	for (int i=1;i<=et;i++)
		to[i]=nx[i]=0;
	et=0;
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
		if (par[i])
			sz[par[i]]++;
	for (int i=1;i<=n;i++)
		if (sz[i]==0)
			if (par[i])
				leaf[par[i]]++;
	ql=0;
	qt=0;
	for (int i=1;i<=n;i++)
		if (sz[i]==leaf[i]&&sz[i]>0)
			q[++qt]=i;
	ans=1;
	while (ql<qt)
	{
		ql++;
		int cur=q[ql];
		ans+=sz[cur]-1;
		int p=par[cur];
		if (p)
		{
			sz[p]--;
			if (sz[p]==leaf[p]&&sz[p]>0)
				q[++qt]=p;
			if (sz[p]==0)
				if (par[p])
				{
					leaf[par[p]]++;
					if (sz[par[p]]==leaf[par[p]])
						q[++qt]=par[p];
				}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}