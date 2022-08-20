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

const int MAXN = 500005;

struct Node
{
	int a[2][2];

	Node(int x = 0, int y = 0, int w = 0, int z = 0)
	{
		a[0][0] = x, a[0][1] = y, a[1][0] = w, a[1][1] = z;
	}

	inline Node Trans()
	{
		return Node(a[1][0], a[0][0] + a[1][1], a[0][0], a[0][1]);
	}

	Node operator + (const Node &b) const
	{
		Node c;
		for (int i = 0; i < 2; i ++)
			for (int j = 0; j < 2; j ++)
				for (int k = 0; k + i < 2; k ++)
					for (int l = 0; l + j < 2; l ++)
						c.a[k + i][l + j] += a[i][j] * b.a[k][l];
		return c;
	}
} f[MAXN], g[MAXN];

vector <int> adj[MAXN];
int n, siz[MAXN];

inline void DFS(int x, int p)
{
	siz[x] = 1, f[x].a[0][0] = 1;
	if (p)
		adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
	for (auto y : adj[x])
		DFS(y, x), f[x] = f[x] + f[y].Trans(), siz[x] += siz[y];
}

inline void DP(int x, int p)
{
	vector <Node> pre;
	Node cur(1, 0, 0, 0);
	if (p)
		pre.pb(g[x].Trans());
	else
		pre.pb(cur);
	for (auto y : adj[x])
		pre.pb(pre.back() + f[y].Trans());
	for (int i = adj[x].size() - 1; ~i; i --)
		g[adj[x][i]] = pre[i] + cur, cur = cur + f[adj[x][i]].Trans(), DP(adj[x][i], x);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	if (n & 1)
		return puts("0"), 0;
	for (int i = 1, x, y; i < n; i ++)
		x = Read(), y = Read(), adj[x].pb(y), adj[y].pb(x);
	DFS(1, 0);
	DP(1, 0);
	LL ans = 0;
	for (int i = 2; i <= n; i ++)
		if (f[i].a[1][0] == 1 && g[i].a[1][0] == 1)
			ans += 1LL * siz[i] * (n - siz[i]);
		else
			ans += 1LL * (f[i].a[0][0] + f[i].a[1][1]) * (g[i].a[0][0] + g[i].a[1][1]);
	cout << ans << endl;
	return 0;
}