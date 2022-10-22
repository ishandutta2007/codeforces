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

const int N = 1005, M = 1e6 + 5, INF = 0x3f3f3f3f;

int n, xl[N], yl[N], xr[N], yr[N], totx, tmpx[N], toty, tmpy[N], ans,
ecnt = 1, nxt[M], adj[N], go[M], cap[M], len, que[N], lev[N], cur[N], S, T;

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; cap[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; cap[ecnt] = 0;
}

bool bfs()
{
	for (int i = S; i <= T; i++) cur[i] = adj[i], lev[i] = -1;
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
	if (res < flow) lev[u] = -1;
	return res;
}

int main()
{
	read(n); read(n);
	for (int i = 1; i <= n; i++)
	{
		read(xl[i]); read(yl[i]); read(xr[i]); read(yr[i]);
		tmpx[++totx] = xl[i]; tmpx[++totx] = xr[i] + 1;
		tmpy[++toty] = yl[i]; tmpy[++toty] = yr[i] + 1;
	}
	std::sort(tmpx + 1, tmpx + totx + 1);
	std::sort(tmpy + 1, tmpy + toty + 1);
	totx = std::unique(tmpx + 1, tmpx + totx + 1) - tmpx - 1;
	toty = std::unique(tmpy + 1, tmpy + toty + 1) - tmpy - 1;
	for (int i = 1; i <= n; i++)
	{
		xl[i] = std::lower_bound(tmpx + 1, tmpx + totx + 1, xl[i]) - tmpx;
		xr[i] = std::lower_bound(tmpx + 1, tmpx + totx + 1, xr[i] + 1) - tmpx - 1;
		yl[i] = std::lower_bound(tmpy + 1, tmpy + toty + 1, yl[i]) - tmpy;
		yr[i] = std::lower_bound(tmpy + 1, tmpy + toty + 1, yr[i] + 1) - tmpy - 1;
	}
	totx--; toty--;
	S = 1; T = totx + toty + 2;
	for (int i = 1; i <= n; i++)
		for (int j = xl[i]; j <= xr[i]; j++)
			for (int k = yl[i]; k <= yr[i]; k++)
				add_edge(1 + j, 1 + totx + k, INF);
	for (int i = 1; i <= totx; i++) add_edge(S, 1 + i, tmpx[i + 1] - tmpx[i]);
	for (int i = 1; i <= toty; i++) add_edge(1 + totx + i, T, tmpy[i + 1] - tmpy[i]);
	while (bfs()) ans += dinic(S, INF);
	return std::cout << ans << std::endl, 0;
}