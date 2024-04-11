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

const int MAXN = 100005;
const int mod = 1e9 + 7;

struct Point
{
	int x, y, i;
	bool operator < (const Point &b) const
	{
		return x < b.x || (x == b.x && y < b.y);
	}
} a[MAXN];

int n, m, bin[MAXN];
bool vis[MAXN];
vector <int> adj[MAXN];
set <int> x, y;

inline void Dfs(int x)
{
	vis[x] = 1, m ++;
	::x.insert(a[x].x), y.insert(a[x].y);
	for (auto y : adj[x])
		if (!vis[y])
			Dfs(y);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), bin[0] = 1;
	for (int i = 1; i <= n + 1; i ++)
		bin[i] = (bin[i - 1] << 1) % mod;
	for (int i = 1; i <= n; i ++)
		a[i].x = Read(), a[i].y = Read(), a[i].i = i;
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1; l <= n; l = r)
	{
		while (r <= n && a[r].x == a[l].x)
			r ++;
		for (int i = l; i + 1 < r; i ++)
			adj[a[i].i].pb(a[i + 1].i), adj[a[i + 1].i].pb(a[i].i);
	}
	for (int i = 1; i <= n; i ++)
		swap(a[i].x, a[i].y);
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1; l <= n; l = r)
	{
		while (r <= n && a[r].x == a[l].x)
			r ++;
		for (int i = l; i + 1 < r; i ++)
			adj[a[i].i].pb(a[i + 1].i), adj[a[i + 1].i].pb(a[i].i);
	}
	sort(a + 1, a + n + 1, [&](Point x, Point y) { return x.i < y.i; });
	int ans = 1;
	for (int i = 1; i <= n; i ++)
		if (!vis[i])
		{
			m = 0, x.clear(), y.clear();
			Dfs(i);
			if (m == x.size() + y.size() - 1)
				ans = 1LL * ans * (bin[m + 1] - 1) % mod;
			else
				ans = 1LL * ans * bin[x.size() + y.size()] % mod;
		}
	return printf("%d\n", ans), 0;
}