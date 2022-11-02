#include <bits/stdc++.h>

using namespace std;

const int N = 200020;
const int mo = 1000000007;

struct Edge{
	int x, y, next;
}edge[N << 1];

int n, tot, ans;
int son[N], size[N], fa[N], f[N][2], g[N][2], a[N];

inline void add(int x, int y)
{
	edge[++tot].x = x; edge[tot].y = y; edge[tot].next = son[x]; son[x] = tot;
}

void dfs(int x)
{
	size[x] = 1;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa[x])continue;
		fa[y] = x;
		dfs(y);
		size[x] += size[y];
	}
}

inline void add(int &x, long long y)
{
	x += y;
	if(x >= mo)x -= mo;
}

inline void dec(int &x, long long y)
{
	x -= y;
	if(x < 0)x += mo;
}

void dfs1(int x)
{
	f[x][1] = 1;
	add(ans, 1ll * a[x] * (n - size[x] + 1) % mo);
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa[x])continue;
		dfs1(y);
		add(f[x][1], 1ll * f[y][0]);
		add(ans, 1ll * a[x] * f[y][0] % mo * (n - size[y]) % mo);
		add(f[x][0], 1ll * f[y][1]);
		dec(ans, 1ll * a[x] * f[y][1] % mo * (n - size[y]) % mo);
	}
}

void dfs2(int x)
{
	g[x][1] = f[fa[x]][0] - f[x][1] + g[fa[x]][0] + 1;
	if(g[x][1] < 0)g[x][1] += mo;
	if(g[x][1] >= mo)g[x][1] -= mo;
	g[x][0] = f[fa[x]][1] - f[x][0] + g[fa[x]][1] - 1;
	if(g[x][0] < 0)g[x][0] += mo;
	if(g[x][0] >= mo)g[x][0] -= mo;
	dec(ans, 1ll * a[x] * g[x][0] % mo * size[x] % mo);
	add(ans, 1ll * a[x] * g[x][1] % mo * size[x] % mo);
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa[x])continue;
		dfs2(y);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		add(a[i], 1ll * mo);
	}
	for(int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1);
	dfs1(1);
	f[0][0] = f[1][1];
	f[0][1] = f[1][0];
	g[0][1] = 1;
	dfs2(1);
	for(int i = 1; i <= n; i++)
		dec(ans, 1ll * a[i] % mo);
	printf("%d\n", ans);
}