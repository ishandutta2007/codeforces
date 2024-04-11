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

const int MAXN = 30005;
const int MAXM = 300005;
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

int n, m, g, ans, typ[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), g = Read(), Flow::Init(n + m + 2), Flow::T = n + m + 1;
	for (int i = 1; i <= n; i ++)
		typ[i] = Read();
	for (int i = 1; i <= n; i ++)
		if (typ[i])
			Flow::Addedge(i, n + m + 1, Read());
		else
			Flow::Addedge(0, i, Read());
	for (int i = 1; i <= m; i ++)
	{
		int typ = Read(), val = Read(), cnt = Read();
		ans += val;
		for (int j = 1; j <= cnt; j ++)
			if (typ)
				Flow::Addedge(Read(), i + n, INF);
			else
				Flow::Addedge(i + n, Read(), INF);
		if (Read())
			val += g;
		if (typ)
			Flow::Addedge(i + n, n + m + 1, val);
		else
			Flow::Addedge(0, i + n, val);
	}
	return printf("%d\n", ans - Flow::Dinic()), 0;
}