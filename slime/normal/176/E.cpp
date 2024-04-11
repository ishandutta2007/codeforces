#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 200005
#define ll long long
using namespace std;
int fa[maxn][20];
int dfn[maxn], bk[maxn], sz[maxn];
int dep[maxn];
ll tf[maxn];
struct edge
{
	int u, v, w;
	edge *next;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v, int w)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->w = w;
	n1->next = h[u], h[u] = n1;
}
int dfcnt = 0;
ll d[maxn];
int lb(int a)
{
	return a & (-a);
}
void ch(int pl, int num)
{
	while(pl < maxn)
		d[pl] += num, 
		pl += lb(pl);
}
int q(int l)
{
	int ans = 0; // check
	while(l)
		ans += d[l], 
		l -= lb(l);
	return ans;
}
int q(int l, int r)
{
	return q(r) - q(l - 1);
}
bool check(int a)
{
	return q(dfn[a], dfn[a] + sz[a] - 1);
}
void dfs(int a)
{
	sz[a] = 1, dfn[a] = ++dfcnt;
	bk[dfn[a]] = a;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa[a][0]) continue;
		dep[p->v] = dep[a] + 1, 
		tf[p->v] = tf[a] + p->w;
		fa[p->v][0] = a;
		for(int i = 1; i < 20; i++)
			fa[p->v][i] = fa[fa[p->v][i - 1]][i - 1];
		dfs(p->v);
		sz[a] += sz[p->v]; 
	}
}
int lca(int a, int b)
{
	if(dep[a] < dep[b])
		swap(a, b);
	for(int i = 19; i >= 0; i--)
		if(dep[fa[a][i]] >= dep[b])
			a = fa[a][i];
	for(int i = 19; i >= 0; i--)
		if(fa[a][i] != fa[b][i])
			a = fa[a][i], 
			b = fa[b][i];
	if(a != b)
		a = fa[a][0], b = fa[b][0];
	return a;
}
ll ans = 0;
set<int> ds; // dfn's
ll cal(int a)
{
	if(ds.empty()) return 0;
	int pre = lca(bk[*ds.begin()], bk[*(--ds.end())]);
	int ns = lca(a, pre);
	if(ns != pre) return tf[a] + tf[pre] - 2 * tf[ns];
	if(check(a)) return 0;
	ll pf = tf[a];
	for(int i = 19; i >= 0; i--)
		if(fa[a][i] == 0) continue;
		else if(!check(fa[a][i]))
			a = fa[a][i];
	a = fa[a][0]; 
	return pf - tf[a];
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c), 
		addedge(b, a, c);
	}
	dep[1] = 1;
	dfs(1);
	int qq;
	scanf("%d", &qq);
	for(int i = 0; i < qq; i++)
	{
		char inp[3];
		scanf("%s", inp);
		if(inp[0] == '?') cout<<ans<<endl;
		else 
		{
			int x;
			scanf("%d", &x);
			if(inp[0] == '+')
				ans += cal(x), 
				ds.insert(dfn[x]), 
				ch(dfn[x], 1);
			else
				ds.erase(dfn[x]), 
				ch(dfn[x], -1), 
				ans -= cal(x);
		}
	}
	return 0;	
}