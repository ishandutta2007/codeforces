#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=1000005;
int n,rt;
int h[N],nx[N];
int f[N],t[N],sz[N];
int av[N];
int tsz,msz;
void dfs(int u)
{
	sz[u]+=t[u];
	for (int i=h[u];i;i=nx[i])
	{
		dfs(i);
		sz[u]+=sz[i];
		if (av[i])
			if (!av[u])
				av[u]=av[i];
			else
			{
				printf("%d %d\n",av[i],av[u]);
				exit(0);
			}
	}
	if (!av[u])
	{
		if (sz[u]==msz)
			av[u]=u;
	}
	else
		if (tsz-sz[u]==msz&&u!=rt)
		{
			printf("%d %d\n",u,av[u]);
			exit(0);
		}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&f[i],&t[i]);
		tsz+=t[i];
		if (!f[i])
		{
			rt=i;
			continue;
		}
		nx[i]=h[f[i]];
		h[f[i]]=i;
	}
	if (tsz%3!=0)
	{
		printf("-1\n");
		return 0;
	}
	msz=tsz/3;
	dfs(rt);
	printf("-1\n");
	return 0;
}