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

const int MAXN = 1000005;

int n, m, ql, qr, ans, q[MAXN], f[MAXN], g[2][MAXN], dep[MAXN], nxt[MAXN][26];
vector <int> adj[MAXN];
bool vis[MAXN];
char s[MAXN];

inline void Add()
{
	scanf("%s", s + 1);
	for (int i = 1, cur = 1; s[i]; cur = nxt[cur][s[i ++] - 'a'])
		if (!nxt[cur][s[i] - 'a'])
			nxt[cur][s[i] - 'a'] = ++ m, dep[m] = dep[cur] + 1;
}

inline void Build()
{
	q[ql = 0] = qr = 1;
	while (ql ^ qr)
	{
		int x = q[ql ++];
		for (int i = 0; i < 26; i ++)
			if (nxt[x][i])
				f[q[qr ++] = nxt[x][i]] = nxt[f[x]][i];
			else
				nxt[x][i] = nxt[f[x]][i];
	}
}

inline void Dfs(int x)
{
	vis[x] = 1, g[0][x] = 0, g[1][x] = 1;
	for (auto y : adj[x])
		if (!vis[y])
			Dfs(y), g[0][x] += max(g[0][y], g[1][y]), g[1][x] += g[0][y];
}

inline void Solve()
{
	n = Read(), m = 1, ans = 0;
	for (int j = 0; j < 26; j ++)
		nxt[0][j] = 1;
	for (int i = 1; i <= n; i ++)
		Add();
	Build();
	for (int i = 2; i <= m; i ++)
		if (f[i] != 1 && dep[i] - dep[f[i]] == 1)
			adj[f[i]].pb(i), adj[i].pb(f[i]);
	for (int i = 2; i <= m; i ++)
		if (!vis[i])
			Dfs(i), ans += max(g[0][i], g[1][i]);
	printf("%d\n", ans);
	for (int i = 2; i <= m; i ++)
		vis[i] = 0, adj[i].clear();
	for (int i = 1; i <= m; i ++)
		for (int j = 0; j < 26; j ++)
			nxt[i][j] = 0;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
		Solve();
	return 0;
}