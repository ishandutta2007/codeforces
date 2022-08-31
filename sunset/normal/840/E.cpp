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

const int MAXN = 50005;
const int MAXM = 256;

int n, Q, a[MAXN], par[MAXN], anc[MAXN], dep[MAXN], f[MAXN][MAXM];
vector <int> adj[MAXN];

inline void Dfs(int x)
{
	for (auto y : adj[x])
		if (y ^ par[x])
			dep[y] = dep[x] + 1, par[y] = x, Dfs(y);
	if (dep[x] >= MAXM)
	{
		int cur = x;
		for (int i = 0, v; i < MAXM; i ++)
			v = (i ^ a[cur]) >> 8, f[x][v ^ 255] = max(f[x][v ^ 255], 255 << 8 | (i ^ a[cur])), cur = par[cur];
		anc[x] = cur;
		for (int j = 0; j < 8; j ++)
			for (int i = 0; i < MAXM; i ++)
				if (!~f[x][i])
					if (~f[x][i ^ 1 << j])
						f[x][i] = f[x][i ^ 1 << j] ^ MAXM << j;
	}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	mset(f, -1);
	n = Read(); Q = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1, x, y; i < n; i ++)
		x = Read(), y = Read(), adj[x].pb(y), adj[y].pb(x);
	dep[1] = 1;
	Dfs(1);
	while (Q --)
	{
		int u = Read(), v = Read(), ret = 0, l = dep[v] - dep[u] + 1, cur = v;
		for (int i = 0; i < l / MAXM; i ++)
			ret = max(ret, f[cur][i]), cur = anc[cur];
		for (int i = l / MAXM * MAXM; i < l; i ++)
			ret = max(ret, a[cur] ^ i), cur = par[cur];
		printf("%d\n", ret);
	}
}