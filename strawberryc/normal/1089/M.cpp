#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)
#define Edge(u) for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])

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

const int N = 11, M = 1005, L = 105;

int n, ecnt, nxt[M], adj[N], go[M], T, dfn[N], low[N], stk[N], top, tot,
ansn, ansm, ansh, ans[L][L][L], bel[N], X, Y, cnte;
bool ins[N], g[N][N], topo[N][N];

std::vector<int> scc[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void dfs(int u)
{
	dfn[u] = low[u] = ++T;
	ins[stk[++top] = u] = 1;
	Edge(u)
		if (!dfn[v])
		{
			dfs(v);
			low[u] = Min(low[u], low[v]);
		}
		else if (ins[v]) low[u] = Min(low[u], dfn[v]);
	if (dfn[u] == low[u])
	{
		ins[u] = 0; int v;
		scc[bel[u] = ++tot].push_back(u);
		while (v = stk[top--], v != u)
			ins[v] = 0, scc[bel[v] = tot].push_back(v);
	}
}

void digout(int layer1, int layer2, int x, int y)
{
	int i;
	For (i, (layer2 << 1), (layer1 - 1 << 1))
	{
		ans[i][x][y] = 0;
		ans[i][x - 1][y] = ans[i][x + 1][y]
		= ans[i][x][y + 1] = ans[i][x][y - 1] = -1;
	}
}

int main()
{
	int i, j, k, x;
	n = read();
	For (i, 1, n) For (j, 1, n)
	{
		g[i][j] = x = read();
		if (x) add_edge(i, j);
	}
	For (i, 1, n) if (!dfn[i]) dfs(i);
	ansn = 9; ansh = (tot << 1) - 1;
	For (i, 1, tot)
	{
		x = scc[i].size();
		For (j, 1, x) ans[(i << 1) - 1][1][j] = scc[i][j - 1];
	}
	For (i, 1, n) For (j, 1, n)
		if (g[i][j] && bel[i] != bel[j]) topo[bel[i]][bel[j]] = 1;
	For (i, 1, tot) For (j, 1, tot) if (topo[i][j]) cnte++;
	ansm = (cnte + 1) / 2 * 4 + 2;
	For (i, 1, tot - 1) For (j, 1, ansm) For (k, 1, 9)
		ans[i << 1][j][k] = -1;
	X = 4; Y = 3; cnte = 0;
	For (i, 1, tot) For (j, 1, tot) if (topo[i][j])
	{
		cnte++;
		digout(i, j, X, Y);
		if (cnte & 1) Y = 7;
		else Y = 3, X += 4;
	}
	std::cout << ansn << " " << ansm << " " << ansh << std::endl;
	Rof (i, ansh, 1)
	{
		For (j, 1, ansm)
		{
			For (k, 1, 9)
				if (ans[i][j][k] == -1) putchar('#');
				else if (ans[i][j][k] == 0) putchar('.');
				else putchar(ans[i][j][k] + '0');
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}