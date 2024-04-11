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

const int MAXN = 205;
const int MAXM = 55;

struct Point
{
	int x, y;
	double k;

	Point(int _x = 0, int _y = 0)
	{
		x = _x, y = _y;
	}

	Point operator - (const Point &b) const
	{
		return Point(x - b.x, y - b.y);
	}

	bool operator < (const Point &b) const
	{
		return k < b.k;
	}

	LL operator * (const Point &b) const
	{
		return 1LL * x * b.y - 1LL * y * b.x;
	}
} a[MAXN], p[MAXN];

int n, m;
LL ans, mx[MAXM], f[MAXN][MAXN][MAXM];
vector <int> adj[MAXN], rev[MAXN];
queue <int> q[MAXN];

inline bool Onleft(Point a, Point b, Point c)
{
	return (b - a) * (c - b) > 0;
}

inline void Add(int x, int y)
{
	while (!q[x].empty() && Onleft(p[q[x].front()], p[x], p[y]))
		Add(q[x].front(), y), q[x].pop();
	rev[x].pb(y);
	adj[y].pb(x);
	q[y].push(x);
}

inline void Init(int n)
{
	for (int i = 1; i <= n; i ++)
	{
		adj[i].clear(), rev[i].clear();
		while (!q[i].empty())
			q[i].pop();
	}
	for (int i = 1; i < n; i ++)
		Add(i, i + 1);
}

inline void Dp(int n)
{
	mset(f, 0);
	for (int i = n; i; i --)
	{
		for (int j = 0; j < m; j ++)
			mx[j] = 0;
		reverse(adj[i].begin(), adj[i].end());
		int cur = rev[i].size() - 1;
		for (auto j : adj[i])
		{
			f[j][i][1] = p[j] * p[i];
			for (int k = 2; k <= m; k ++)
				if (mx[k - 1])
					f[j][i][k] = mx[k - 1] + p[j] * p[i];
			for (; ~cur && Onleft(p[j], p[i], p[rev[i][cur]]); cur --)
				for (int k = 1; k < m; k ++)
					if (mx[k] < f[i][rev[i][cur]][k])
						mx[k] = f[i][rev[i][cur]][k], f[j][i][k + 1] = mx[k] + p[j] * p[i];
		}
	}
	for (int i = 1; i <= n; i ++)
		for (auto j : rev[i])
			ans = max(ans, f[i][j][m - 2]);
}

inline void Solve(int idx)
{
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		if (i ^ idx)
			if (a[i].x > a[idx].x || (a[i].x == a[idx].x && a[i].y > a[idx].y))
				p[++ cnt] = a[i] - a[idx], p[cnt].k = atan2(p[cnt].y, p[cnt].x);
	sort(p + 1, p + cnt + 1);
	Init(cnt);
	Dp(cnt);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		a[i].x = Read(), a[i].y = Read();
	for (int i = 1; i <= n; i ++)
		Solve(i);
	cout << ans / 2 << "." << (ans & 1 ? "50" : "00") << endl;
	return 0;	
}