#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pii;

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

const int MAXN = 500005;
const int INF = 0x3f3f3f3f;

struct Node { int v, x, t, i; bool operator < (const Node &b) const { return v > b.v; } };
struct Edge { int p, l, r, v; };
int n, m, cur[MAXN][2];
vector < Edge > G[MAXN];
vector < pii > adj[MAXN][2];
vector < int > f[MAXN][2];
priority_queue < Node > Q;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	if (n == 1)
		return puts("0"), 0;
	for (int i = 1, u, v, l, r; i <= m; i ++)
		u = Read(), v = Read(), l = Read(), r = Read(), G[u].pb({v, l, r, G[v].size()}), G[v].pb({u, l, r, G[u].size() - 1});
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < 2; j ++)
		{
			f[i][j].resize(G[i].size(), INF);
			for (int k = 0; k < G[i].size(); k ++)
				adj[i][j].pb(mp(G[i][k].l + ((G[i][k].l & 1) ^ j), k));
			sort(adj[i][j].begin(), adj[i][j].end());
		}
	for (int i = 0; i < G[1].size(); i ++)
		if (!G[1][i].l)
			f[1][0][i] = 0, Q.push({0, 1, 0, i});
	/*
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < G[i].size(); j ++)
			printf("edge[%d][%d].p = %d\n", i, j, G[i][j].p);
	*/
	while (!Q.empty())
	{
		Node tmp = Q.top(); Q.pop();
		int x = tmp.x, t = tmp.t, p = tmp.i, r = G[x][p].v, y = G[x][p].p, v = f[x][t][p], d = G[x][p].r - ((G[x][p].r & 1) ^ t);
		if (tmp.v > v)
			continue;
		//printf("%d %d %d %d\n", x, t, p, v);
		if (f[y][t ^ 1][r] > v + 1 && G[x][p].l <= v + 1 && G[x][p].r >= v + 1)
			f[y][t ^ 1][r] = v + 1, Q.push({v + 1, y, t ^ 1, r});
		if (v > d)
			continue;
		while (cur[x][t] < G[x].size())
		{
			pii g = adj[x][t][cur[x][t]];
			if (g.xx > d)
				break;
			if (max(g.xx, v) < f[x][t][g.yy])
				f[x][t][g.yy] = max(g.xx, v), Q.push({max(g.xx, v), x, t, g.yy});
			cur[x][t] ++;
		}
	}
	int ans = INF;
	for (int i = 0; i < G[n].size(); i ++)
		for (int j = 0; j < 2; j ++)
			ans = min(ans, f[n][j][i]);
	if (ans == INF)
		ans = -1;
	return printf("%d\n", ans), 0;
}