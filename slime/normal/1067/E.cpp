#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define mod 998244353
#define maxn 500005
#define ll long long
using namespace std;
int sz[maxn], pw[maxn];
ll ans[maxn];
struct edge
{
	int u, v;
	edge *next;	
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v;
	n1->next = h[u], h[u] = n1;
}
void dfs(int a, int fa)
{
	sz[a] = 1;
	ll nans = 1;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
		dfs(p->v, a);
		sz[a] += sz[p->v];
		nans *= (pw[sz[p->v] - 1] + ans[p->v]),
		nans %= mod;
	}
	ans[a] = pw[sz[a] - 1] - nans;
	ans[a] %= mod;
}
int main()
{
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	dfs(1, 0);
	ll res = 0;
	for(int i = 1; i <= n; i++)
		ans[i] *= pw[n - sz[i]], ans[i] %= mod;
	for(int i = 1; i <= n; i++)
		res += ans[i];//, cout<<ans[i]<<" ";
	res *= 2, res %= mod;
	if(res < 0) res += mod;
	printf("%lld\n", res);
	return 0;
}