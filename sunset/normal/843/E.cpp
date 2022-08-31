#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 105;
const int MAXM = 10005;
const int INF = 0x3f3f3f3f;

namespace Flow
{
	struct Edge
	{
		int p, v, w;
	} e[MAXM];

	int e_cnt, S, T, V, ql, qr, q[MAXN], hed[MAXN], dis[MAXN], cur[MAXN];

	inline void Init(int n)
	{
		V = n;
		for (int i = 0; i < V; i ++)
			hed[i] = 0;
		e_cnt = 1;
	}

	inline void Addedge(int x, int y, int w)
	{
		e[++ e_cnt] = {y, hed[x], w}; hed[x] = e_cnt;
		e[++ e_cnt] = {x, hed[y], 0}; hed[y] = e_cnt;
	}

	inline bool Bfs()
	{
		for (int i = 0; i < V; i ++)
			dis[i] = 0;
		dis[q[ql = 0] = S] = qr = 1;
		while (ql ^ qr)
		{
			int x = q[ql ++];
			for (int i = hed[x]; i; i = e[i].v)
				if (e[i].w && !dis[e[i].p])
					dis[q[qr ++] = e[i].p] = dis[x] + 1;
		}
		return dis[T];
	}

	inline int Dfs(int x, int f)
	{
		if (x == T)
			return f;
		int ret = 0, t = 0;
		for (int &i = cur[x]; i; i = e[i].v)
			if (e[i].w && dis[e[i].p] == dis[x] + 1)
			{
				t = Dfs(e[i].p, min(f, e[i].w));
				f -= t; ret += t; e[i].w -= t; e[i ^ 1].w += t;
				if (!f)
					return ret;
			}
		return dis[x] = -1, ret;
	}

	inline int Dinic()
	{
		int ret = 0;
		while (Bfs())
		{
			for (int i = 0; i < V; i ++)
				cur[i] = hed[i];
			ret += Dfs(S, INF);
		}
		return ret;
	}
}

int n, m, s, t, d[MAXN], u[MAXM], v[MAXM], f[MAXM], g[MAXM];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), s = Read(), t = Read();
	Flow::Init(n + 1); Flow::S = s; Flow::T = t;
	for (int i = 1; i <= m; i ++)
		u[i] = Read(), v[i] = Read(), g[i] = Read(), Flow::Addedge(u[i], v[i], g[i] ? 1 : INF), d[u[i]] ++, d[v[i]] --;
	for (int i = 1; i <= m; i ++)
		if (g[i])
			Flow::Addedge(v[i], u[i], INF);
	printf("%d\n", Flow::Dinic());
	for (int i = 1; i <= m; i ++)
		if (g[i])
			if (Flow::dis[u[i]] && !Flow::dis[v[i]])
				f[i] = 1;
	Flow::Init(n + 2); Flow::S = 0, Flow::T = n + 1;
	for (int i = 1; i <= m; i ++)
		if (g[i])
			Flow::Addedge(u[i], v[i], INF);
	Flow::Addedge(t, s, INF);
	for (int i = 1; i <= n; i ++)
		if (d[i] > 0)
			Flow::Addedge(i, n + 1, d[i]);
		else
			Flow::Addedge(0, i, -d[i]);
	Flow::Dinic();
	for (int i = 1, cnt = 0; i <= m; i ++)
		if (!g[i])
			puts("0 1");
		else
			cnt ++, printf("%d %d\n", Flow::e[cnt << 1 | 1].w + 1, Flow::e[cnt << 1 | 1].w + (!f[i]) + 1);
	return 0;
}