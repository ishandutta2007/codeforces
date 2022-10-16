#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=200005;
int n,m;
int i,j,k;
long long w[maxn];
int h[maxn],to[maxn*2],nx[maxn*2];
long long wt[maxn*2];
int u,v,et;
long long x;
long long ans[maxn];
bool vis[maxn];
struct nd
{
	int p;
	long long v;
	nd (int x,long long y)
	{
		p=x;
		v=y;
	}
};
bool operator < (nd x,nd y)
{
	return x.v>y.v;
}

priority_queue <nd> q;
bool cmp(int x,int y)
{
	return w[x]<w[y];
}
void addedge(int u,int v,long long x)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	wt[et]=x;
	h[u]=et;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%I64d",&u,&v,&x);
		addedge(u,v,x);
		addedge(v,u,x);
	}
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&w[i]);
		q.push(nd(i,w[i]));
		ans[i]=w[i];
	}
	for (i=1;i<=n;i++)
	{
		nd ret=q.top();
		q.pop();
		while (vis[ret.p])
		{
			ret=q.top();
			q.pop();
		}
		ans[ret.p]=ret.v;
		vis[ret.p]=1;
		for (j=h[ret.p];j;j=nx[j])
			if (ans[ret.p]+wt[j]*2<ans[to[j]])
			{
				ans[to[j]]=ans[ret.p]+wt[j]*2;
				q.push(nd(to[j],ans[to[j]]));
			}
	}
	for (i=1;i<=n;i++)
		printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}