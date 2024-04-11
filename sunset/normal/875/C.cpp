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

const int MAXN = 200005;
const int N = 100001;

int n, m, tim, top, num, ql, qr, q[MAXN], deg[MAXN], dfn[MAXN], low[MAXN], scc[MAXN], sta[MAXN];
vector <int> s[MAXN], G[MAXN], adj[MAXN];

inline void Dfs(int x)
{
	dfn[x] = low[x] = ++ tim;
	sta[++ top] = x;
	for (auto y : adj[x])
		if (!dfn[y])
			Dfs(y), low[x] = min(low[x], low[y]);
		else if (!scc[y])
			low[x] = min(low[x], dfn[y]);
	if (low[x] == dfn[x])
	{
		num ++;
		for (int k = -1; k ^ x; scc[k = sta[top --]] = num);
	}
}

inline void Solve(int l, int r, int p)
{
	for (int i = l; i < r; i ++)
		if (s[i][p] > s[i + 1][p])
			adj[s[i][p] + N].pb(s[i][p]), adj[s[i + 1][p]].pb(s[i + 1][p] + N);
		else if (s[i][p] < s[i + 1][p])
			adj[s[i][p] + N].pb(s[i + 1][p] + N), adj[s[i + 1][p]].pb(s[i][p]);
	int lst = l;
	for (int i = l; i <= r; i ++)
		if (i == r || (s[i][p] ^ s[i + 1][p]))
		{
			if (s[i][p])
				Solve(lst, i, p + 1);
			lst = i + 1;
		}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
	{
		int cnt = Read();
		while (cnt --)
			s[i].pb(Read());
		s[i].pb(0);
	}
	Solve(1, n, 0);
	adj[N].pb(0);
	for (int i = 0; i <= m; i ++)
		if (!dfn[i])
			Dfs(i);
	for (int i = 0; i <= m; i ++)
		if (!dfn[i + N])
			Dfs(i + N);
	for (int i = 0; i <= m; i ++)
		if (scc[i] == scc[i + N])
			return puts("No"), 0;
	for (int x = 0; x <= m; x ++)
		for (auto y : adj[x])
			if (scc[x] ^ scc[y])
				G[scc[y]].pb(scc[x]), deg[scc[x]] ++;
	for (int x = N; x <= m + N; x ++)
		for (auto y : adj[x])
			if (scc[x] ^ scc[y])
				G[scc[y]].pb(scc[x]), deg[scc[x]] ++;
	for (int i = 1; i <= num; i ++)
		if (!deg[i])
			q[++ qr] = i;
	while (ql ^ qr)
	{
		int x = q[++ ql];
		for (auto y : G[x])
			if (!-- deg[y])
				q[++ qr] = y;
	}
	vector <int> ans;
	for (int i = 1; i <= qr; i ++)
		dfn[q[i]] = i;
	for (int i = 1; i <= m; i ++)
		if (dfn[scc[i]] < dfn[scc[i + N]])
			ans.pb(i);
	puts("Yes");
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d ", x);
	putchar(10);
	return 0;
}