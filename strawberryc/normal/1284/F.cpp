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

const int N = 25e4 + 5, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], a[N], b[N], ufs[N], fa[N], lc[N], rc[N],
rev[N], len, que[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

int dfs(int u, int fu, int tot)
{
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) tot = dfs(v, u, tot), a[++tot] = v, b[tot] = u;
	return tot;
}

int cx(int x)
{
	if (ufs[x] != x) ufs[x] = cx(ufs[x]);
	return ufs[x];
}

void zm(int x, int y)
{
	if ((x = cx(x)) != (y = cx(y))) ufs[y] = x;
}

bool which(int x) {return rc[fa[x]] == x;}

bool isRoot(int x)
{
	return lc[fa[x]] != x && rc[fa[x]] != x;
}

void down(int x)
{
	if (rev[x])
	{
		std::swap(lc[x], rc[x]);
		if (lc[x]) rev[lc[x]] ^= 1;
		if (rc[x]) rev[rc[x]] ^= 1;
		rev[x] = 0;
	}
}

void rotate(int x)
{
	int y = fa[x], z = fa[y], b = lc[y] == x ? rc[x] : lc[x];
	if (!isRoot(y)) (lc[z] == y ? lc[z] : rc[z]) = x;
	fa[x] = z; fa[y] = x; if (b) fa[b] = y;
	if (lc[y] == x) rc[x] = y, lc[y] = b;
	else lc[x] = y, rc[y] = b;
}

void splay(int x)
{
	que[len = 1] = x;
	for (int y = x; !isRoot(y); y = fa[y]) que[++len] = fa[y];
	for (int i = len; i >= 1; i--) down(que[i]);
	while (!isRoot(x))
	{
		if (!isRoot(fa[x]))
		{
			if (which(x) ^ which(fa[x])) rotate(x);
			else rotate(fa[x]);
		}
		rotate(x);
	}
}

void access(int x)
{
	for (int y = 0; x; y = x, x = fa[x])
	{
		splay(x); rc[x] = y;
		if (y) fa[y] = x;
	}
}

void makeroot(int x)
{
	access(x); splay(x); rev[x] ^= 1;
}

void link(int x, int y)
{
	makeroot(x); fa[x] = y;
}

void cut(int x, int y)
{
	makeroot(x); access(y); splay(y);
	lc[y] = fa[x] = 0;
}

int fp(int x, int y)
{
	makeroot(x); access(y); splay(y);
	int pre, res, lst;
	while (y)
		if (down(lst = y), cx(x) == cx(y)) pre = y, y = rc[y];
		else res = y, y = lc[y];
	return splay(lst), printf("%d %d\n", pre, res), res;
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++) ufs[i] = i;
	for (int i = 1; i < n; i++) read(x), read(y), link(x, y);
	std::cout << n - 1 << std::endl;
	for (int i = 1; i < n; i++)
	{
		printf("%d %d ", a[i], b[i]);
		cut(a[i], fp(a[i], b[i])); link(a[i], b[i]);
		zm(a[i], b[i]);
	}
	return 0;
}