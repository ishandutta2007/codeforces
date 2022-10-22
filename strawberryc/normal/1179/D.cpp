#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 5e5 + 5, M = N << 1;
const ll INF = 1e18;

int n, ecnt, nxt[M], adj[N], go[M], sze[N], tot, top;
ll ans = INF, f[N];

struct point
{
	ll x, y;
	
	friend inline point operator - (point a, point b)
	{
		return (point) {b.x - a.x, b.y - a.y};
	}
	
	friend inline ll operator * (point a, point b)
	{
		return a.x * b.y - a.y * b.x;
	}
} p[N], stk[N];

inline bool comp(point a, point b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	sze[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
	{
		if ((v = go[e]) == fu) continue;
		dfs(v, u);
		sze[u] += sze[v];
	}
	f[u] = 1ll * sze[u] * (sze[u] - 1);
	tot = top = 0;
	for (int e = adj[u], v; e; e = nxt[e])
	{
		if ((v = go[e]) == fu) continue;
		f[u] = Min(f[u], 1ll * (sze[u] - sze[v]) * (sze[u] - sze[v] - 1) + f[v]);
		ans = Min(ans, f[v] + 1ll * (n - sze[v]) * (n - sze[v] - 1));
		p[++tot] = (point) {
			sze[v], f[v] - 1ll * ((n << 1) - 1) * sze[v] + 1ll * sze[v] * sze[v]};
	}
	std::sort(p + 1, p + tot + 1, comp);
	for (int i = 1; i <= tot; i++)
	{
		while (top > 1 && stk[top].y + p[i].x * stk[top].x * 2 >=
			stk[top - 1].y + p[i].x * stk[top - 1].x * 2) top--;
		if (i > 1) ans = Min(ans, 1ll * n * (n - 1)
			+ p[i].y + stk[top].y + p[i].x * stk[top].x * 2);
		while (top > 1 && (stk[top - 1] - stk[top]) * (stk[top - 1] - p[i]) <= 0)
			top--;
		stk[++top] = p[i];
	}
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i < n; i++)
		read(x), read(y), add_edge(x, y);
	dfs(1, 0);
	return std::cout << 1ll * n * (n - 1) - (ans >> 1) << std::endl, 0;
}