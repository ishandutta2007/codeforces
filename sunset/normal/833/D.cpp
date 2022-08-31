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

struct Edge { int p, w, t; };
struct Node { int r, b, v; };
int n, siz[MAXN], ans = 1, bit[MAXN << 2];
vector <Edge> adj[MAXN];
bool vis[MAXN];

inline int Qpow(int x, int y) { int r = 1; for (; y; y >>= 1, x = 1LL * x * x % mod) if (y & 1) r = 1LL * r * x % mod; return r; }

inline void FindR(int x, int p, int Siz, int &cg)
{
	int f = siz[x] = 1;
	for (auto y : adj[x])
		if (y.p ^ p)
			if (!vis[y.p])
				FindR(y.p, x, Siz, cg), f &= siz[y.p] <= Siz >> 1, siz[x] += siz[y.p];
	f &= siz[x] >= Siz >> 1;
	if (f)
		cg = x;
}

inline void FindS(int x, int p)
{
	siz[x] = 1;
	for (auto y : adj[x])
		if (y.p ^ p)
			if (!vis[y.p])
				FindS(y.p, x), siz[x] += siz[y.p];
}

inline void Dfs(int x, int p, Node c, vector <Node> &cur)
{
	cur.pb(c);
	for (auto y : adj[x])
		if (y.p ^ p)
			if (!vis[y.p])
				Dfs(y.p, x, {c.r + y.t, c.b + !y.t, 1LL * c.v * y.w % mod}, cur);
}

inline int Lowbit(int x) { return x & -x; }
inline void Modify(int x, int v) { for (x += n << 1; x <= n << 2; x += Lowbit(x)) bit[x] += v; }
inline int Query(int x) { int ret = 0; for (x += n << 1; x; x -= Lowbit(x)) ret += bit[x]; return ret; }

inline int Cal(vector <Node> v)
{
	int ret = 1;
	for (auto x : v)
		Modify(2 * x.b - x.r, 1);
	for (auto x : v)
		ret = 1LL * ret * Qpow(x.v, Query(x.r - 2 * x.b - 1)) % mod;
	for (auto x : v)
		Modify(2 * x.b - x.r, -1);
	for (auto x : v)
		Modify(2 * x.r - x.b, 1);
	for (auto x : v)
		ret = 1LL * ret * Qpow(x.v, Query(x.b - 2 * x.r - 1)) % mod;
	for (auto x : v)
		Modify(2 * x.r - x.b, -1);
	ret = Qpow(ret, mod - 2);
	for (auto x : v)
		ret = 1LL * ret * Qpow(x.v, v.size()) % mod;
	return ret;
}

inline void Solve(int x, int Siz)
{
	int cg;
	FindR(x, 0, Siz, cg);
	FindS(x = cg, 0);
	vis[x] = 1;
	vector <Node> all, cur;
	for (auto y : adj[x])
		if (!vis[y.p])
		{
			cur.clear();
			Dfs(y.p, x, {y.t, !y.t, y.w}, cur);
			ans = 1LL * ans * Qpow(Cal(cur), mod - 2) % mod;
			for (auto c : cur)
				all.pb(c);
		}
	all.pb({0, 0, 1});
	ans = 1LL * ans * Cal(all) % mod;
	for (auto y : adj[x])
		if (!vis[y.p])
			Solve(y.p, siz[y.p]);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1, u, v, w, t; i < n; i ++)
		u = Read(), v = Read(), w = Read(), t = Read(), adj[u].pb({v, w, t}), adj[v].pb({u, w, t});
	Solve(1, n);
	return printf("%d\n", ans), 0;
}