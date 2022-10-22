#include <bits/stdc++.h>

// 0830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

inline char get()
{
	char c;
	while ((c = getchar()) != 'u' && c != 'w' && c != 'c');
	return c;
}

const int N = 4e5 + 5;

int n, m, q, ecnt, nxt[N], adj[N], go[N], A[N], fa[N], lc[N], rc[N], d[N],
sze[N], col[N], rev[N], len, que[N];

std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; d[u]++;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; d[v]++;
}

void change(int x, int v)
{
	for (; x <= n + q; x += x & -x)
		A[x] += v;
}

int ask(int x)
{
	int res = 0;
	for (; x; x -= x & -x)
		res += A[x];
	return res;
}

int which(int x) {return rc[fa[x]] == x;}

bool isroot(int x)
{
	return !fa[x] || (lc[fa[x]] != x && rc[fa[x]] != x);
}

void down(int x)
{
	if (rev[x])
		Swap(lc[x], rc[x]), rev[x] = 0,
		rev[lc[x]] ^= 1, rev[rc[x]] ^= 1;
}

void upt(int x)
{
	sze[x] = sze[lc[x]] + sze[rc[x]] + 1;
}

void init(int u, int fu)
{
	fa[u] = fu;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) init(v, u);
}

void rotate(int x)
{
	int y = fa[x], z = fa[y], b = lc[y] == x ? rc[x] : lc[x];
	col[x] = col[y]; col[y] = 0;
	if (z && !isroot(y)) (lc[z] == y ? lc[z] : rc[z]) = x;
	fa[x] = z; fa[y] = x; if (b) fa[b] = y;
	if (lc[y] == x) rc[x] = y, lc[y] = b;
	else lc[x] = y, rc[y] = b; upt(y); upt(x);
}

void splay(int x)
{
	que[len = 1] = x;
	for (int y = x; !isroot(y); y = fa[y]) que[++len] = fa[y];
	for (int i = len; i >= 1; i--) down(que[i]);
	while (!isroot(x))
	{
		if (!isroot(fa[x]))
		{
			if (which(x) == which(fa[x])) rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
}

void access(int x)
{
	int c = ++m;
	for (int y = 0; x; y = x, x = fa[x])
	{
		splay(x);
		if (rc[x]) col[rc[x]] = col[x];
		change(col[x], sze[rc[x]] - sze[x]);
		change(c, sze[x] - sze[rc[x]]);
		rc[x] = y; col[x] = c; col[y] = 0;
		if (y) fa[y] = x; upt(x);
	}
}

void makeroot(int x)
{
	access(x); splay(x); rev[x] ^= 1;
}

int rk(int x)
{
	splay(x);
	return ask(col[x] - 1) + sze[rc[x]] + 1;
}

int main()
{
	char c;
	int x, y;
	m = n = read(); q = read();
	for (int i = 1; i < n; i++)
		x = read(), y = read(), add_edge(x, y);
	for (int i = 1; i <= n; i++) if (d[i] <= 1) pq.push(i);
	for (int i = 1; i <= n; i++)
	{
		sze[i] = 1;
		int u = pq.top(); pq.pop();
		col[u] = i; change(i, 1);
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (!col[v] && (--d[v]) <= 1) pq.push(v);
	}
	init(n, 0);
	for (int T = 1; T <= q; T++)
	{
		c = get(); x = read();
		if (c == 'u') makeroot(x);
		else if (c == 'w') printf("%d\n", rk(x));
		else y = read(), printf("%d\n", rk(x) < rk(y) ? x : y);
	}
	return 0;
}