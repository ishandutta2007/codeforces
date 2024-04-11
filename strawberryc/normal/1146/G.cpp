#include <bits/stdc++.h>

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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e6 + 5, INF = 0x3f3f3f3f;

int n, h, m, l[N], r[N], x[N], c[N], ecnt = 1, nxt[N], adj[N], go[N], cap[N],
len, que[N], S, T, lev[N], cur[N];

int which(int x, int y)
{
	return 1 + (x - 1) * h + y;
}

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; cap[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; cap[ecnt] = 0;
}

bool bfs()
{
	for (int i = S; i <= T; i++) lev[i] = -1, cur[i] = adj[i];
	lev[que[len = 1] = S] = 0;
	for (int i = 1; i <= len; i++)
	{
		int u = que[i];
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (cap[e] && lev[v] == -1)
			{
				lev[que[++len] = v] = lev[u] + 1;
				if (v == T) return 1;
			}
	}
	return 0;
}

int dinic(int u, int flow)
{
	if (u == T) return flow;
	int res = 0, delta;
	for (int &e = cur[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (cap[e] && lev[u] < lev[v])
		{
			delta = dinic(v, Min(cap[e], flow - res));
			if (delta)
			{
				cap[e] -= delta; cap[e ^ 1] += delta;
				res += delta; if (res == flow) break;
			}
		}
	if (res != flow) lev[u] = -1;
	return res;
}

int maxflow()
{
	int res = 0;
	while (bfs()) res += dinic(S, INF);
	return res;
}

int main()
{
	n = read(); h = read(); m = read();
	for (int i = 1; i <= m; i++)
		l[i] = read(), r[i] = read(), x[i] = read() + 1, c[i] = read();
	S = 1; T = n * h + m + 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= h; j++)
		{
			add_edge(S, which(i, j), (j << 1) - 1);
			if (j > 1) add_edge(which(i, j), which(i, j - 1), INF);
		}
	for (int i = 1; i <= m; i++) if (x[i] <= h)
		for (int j = l[i]; j <= r[i]; j++)
			add_edge(which(j, x[i]), 1 + n * h + i, INF);
	for (int i = 1; i <= m; i++) add_edge(1 + n * h + i, T, c[i]);
	return std::cout << n * h * h - maxflow() << std::endl, 0;
}