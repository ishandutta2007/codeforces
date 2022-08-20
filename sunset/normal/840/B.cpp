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

const int MAXN = 300005;

vector <pii> adj[MAXN];
int a[MAXN], ans[MAXN], tp, n, m, p, s;
bool v[MAXN];

inline void Dfs(int x)
{
	v[x] = 1;
	for (auto y : adj[x])
		if (!v[y.xx])
		{
			Dfs(y.xx);
			if (a[y.xx])
				a[x] ^= 1, ans[++ tp] = y.yy;
		}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; s ^= a[i ++])
		if (!~(a[i] = Read()))
			a[i] = 0, p = i;
	if (s && !p)
		return puts("-1"), 0;
	if (s)
		a[p] = 1;
	for (int i = 1, x, y; i <= m; i ++)
		x = Read(), y = Read(), adj[x].pb(mp(y, i)), adj[y].pb(mp(x, i));
	Dfs(1);
	printf("%d\n", tp);
	for (int i = 1; i <= tp; i ++)
		printf("%d\n", ans[i]);
}