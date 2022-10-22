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

const int N = 1e5 + 5, M = N << 1, L = 12e5 + 5, LogN = 21, rqy = 1e9 + 7;

int n, m, ecnt, nxt[M], adj[N], go[M], id[M], son[L][10], dep[L],
tot = 1, fa[L][LogN], ns, tmp[N], nm[L], f[N], pt[N], fh;
bool vis[N];

void add_edge(int u, int v, int i)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; id[ecnt] = i;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; id[ecnt] = i;
}

void addlea(int u, int x)
{
	int v = ++tot;
	son[u][x] = v; dep[v] = dep[u] + 1;
	fa[v][0] = u; nm[v] = x;
	for (int i = 0; i < 20; i++) fa[v][i + 1] = fa[fa[v][i]][i];
}

int extend(int y, int u, int num)
{
	ns = 0; fh = f[y];
	while (num) tmp[++ns] = num % 10, num /= 10;
	for (int i = ns; i >= 1; i--)
	{
		if (!son[u][tmp[i]]) addlea(u, tmp[i]);
		u = son[u][tmp[i]]; fh = (10ll * fh + tmp[i]) % rqy;
	}
	return u;
}

int _compare(int x, int y)
{
	if (x == y) return 0;
	if (dep[x] > dep[y]) return 1;
	if (dep[x] < dep[y]) return 0;
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return nm[x] > nm[y];
}

struct node
{
	int u, x;
	
	friend inline bool operator < (node a, node b)
	{
		return _compare(a.x, b.x);
	}
};

std::priority_queue<node> pq;

int main()
{
	int x, y;
	read(n); read(m);
	for (int i = 1; i <= m; i++)
		read(x), read(y), add_edge(x, y, i);
	pq.push((node) {dep[1] = 1, pt[1] = 1});
	while (!pq.empty())
	{
		node ux = pq.top(); pq.pop(); int u = ux.u;
		if (vis[u]) continue; vis[u] = 1;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		{
			int wt = extend(u, pt[u], id[e]);
			if (!pt[v] || _compare(pt[v], wt))
				pt[v] = wt, f[v] = fh, pq.push((node) {v, wt});
		}
	}
	for (int i = 2; i <= n; i++) printf("%d\n", f[i]);
	return 0;
}