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
	int r = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		r = r * 10 + c - '0';
	return r * f;
}

const int MAXN = 100005;
const int MAXM = 5000011;

int n, mod, bas, okv, a[MAXN], ind[MAXN], oud[MAXN], pw[MAXN], inv[MAXN], siz[MAXN];
vector <int> adj[MAXN];
bool vis[MAXN];

struct HashTable
{
	int hed[MAXM], vis[MAXM], p[MAXN], v[MAXN], w[MAXN], e_cnt, tim;
	
	inline void Clear()
	{
		tim ++, e_cnt = 0;
	}

	inline int Hed(int x)
	{
		if (vis[x] == tim)
			return hed[x];
		vis[x] = tim, hed[x] = 0;
		return hed[x];
	}

	inline void Add(int x)
	{
		int t = x % MAXM;
		for (int i = Hed(t); i; i = v[i])
			if (p[i] == x)
				return (void)(w[i] ++);
		e_cnt ++;
		p[e_cnt] = x, v[e_cnt] = hed[t], w[e_cnt] = 1, hed[t] = e_cnt;
	}

	inline int Get(int x)
	{
		int t = x % MAXM;
		for (int i = Hed(t); i; i = v[i])
			if (p[i] == x)
				return w[i];
		return 0;
	}
} ht;

inline int Qow(int x, int y)
{
	int r = 1;
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1)
			r = 1LL * r * x % mod;
	return r;
}

inline void FindRoot(int x, int p, int Siz, int &cg)
{
	siz[x] = 1;
	bool f = true;
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			FindRoot(adj[x][i], x, Siz, cg), f &= (siz[adj[x][i]] <= Siz >> 1), siz[x] += siz[adj[x][i]];
	f &= (siz[x] >= Siz >> 1);
	if (f)
		cg = x;
}

inline void GetSize(int x, int p)
{
	siz[x] = 1;
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			GetSize(adj[x][i], x), siz[x] += siz[adj[x][i]];
}

inline void DfsFromRoot(int x, int p, int r, int d, int cur)
{
	if (cur == okv)
		ind[r] ++, oud[x] ++;
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			DfsFromRoot(adj[x][i], x, r, d + 1, (1LL * a[adj[x][i]] * pw[d + 1] + cur) % mod);
}

inline void DfsToRoot(int x, int p, int r, int cur)
{
	if (cur == okv)
		ind[x] ++, oud[r] ++;
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			DfsToRoot(adj[x][i], x, r, (1LL * cur * bas + a[adj[x][i]]) % mod);
}

inline void AddToInd(int x, int p, int d, int cur)
{
	ind[x] += ht.Get(1LL * (okv - cur + mod) * inv[d] % mod);
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			AddToInd(adj[x][i], x, d + 1, (1LL * cur * bas + a[adj[x][i]]) % mod);
}

inline void AddToInTable(int x, int p, int d, int cur)
{
	ht.Add(cur);
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			AddToInTable(adj[x][i], x, d + 1, (1LL * a[adj[x][i]] * pw[d + 1] + cur) % mod);
}

inline void AddToOud(int x, int p, int d, int cur)
{
	oud[x] += ht.Get(cur);
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			AddToOud(adj[x][i], x, d + 1, (1LL * a[adj[x][i]] * pw[d + 1] + cur) % mod);
}

inline void AddToOuTable(int x, int p, int d, int cur)
{
	ht.Add(1LL * (okv - cur + mod) * inv[d] % mod);
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]] && (adj[x][i] ^ p))
			AddToOuTable(adj[x][i], x, d + 1, (1LL * cur * bas + a[adj[x][i]]) % mod);
}

inline void Solve(int x, int Siz)
{
	int cg;
	FindRoot(x, 0, Siz, cg);
	GetSize(x = cg, 0);
	vis[x] = true;
	DfsFromRoot(x, 0, x, 0, a[x]);
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]])
			DfsToRoot(adj[x][i], x, x, (1LL * a[x] * bas + a[adj[x][i]]) % mod);
	ht.Clear();
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]])
			AddToInd(adj[x][i], x, 1, a[adj[x][i]]), AddToInTable(adj[x][i], x, 1, (1LL * a[adj[x][i]] * bas + a[x]) % mod);
	ht.Clear();
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]])
			AddToOud(adj[x][i], x, 1, 1LL * bas * a[adj[x][i]] % mod), AddToOuTable(adj[x][i], x, 1, (1LL * a[x] * bas + a[adj[x][i]]) % mod);
	ht.Clear();
	reverse(adj[x].begin(), adj[x].end());
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]])
			AddToInd(adj[x][i], x, 1, a[adj[x][i]]), AddToInTable(adj[x][i], x, 1, (1LL * a[adj[x][i]] * bas + a[x]) % mod);
	ht.Clear();
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]])
			AddToOud(adj[x][i], x, 1, 1LL * bas * a[adj[x][i]] % mod), AddToOuTable(adj[x][i], x, 1, (1LL * a[x] * bas + a[adj[x][i]]) % mod);
	for (int i = 0; i < adj[x].size(); i ++)
		if (!vis[adj[x][i]])
			Solve(adj[x][i], siz[adj[x][i]]);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), mod = Read(), bas = Read(), okv = Read();
	pw[0] = inv[0] = 1;
	for (int i = 1, v = Qow(bas, mod - 2); i <= n; i ++)
		a[i] = Read(), pw[i] = 1LL * pw[i - 1] * bas % mod, inv[i] = 1LL * inv[i - 1] * v % mod;
	for (int i = 1, x, y; i < n; i ++)
		x = Read(), y = Read(), adj[x].pb(y), adj[y].pb(x);
	Solve(1, n);
	LL ret = 0;
	for (int i = 1; i <= n; i ++)
		ret += 2LL * ind[i] * (n - ind[i]) + 2LL * oud[i] * (n - oud[i]) + 1LL * ind[i] * (n - oud[i]) + 1LL * oud[i] * (n - ind[i]);
	ret = 1LL * n * n * n - ret / 2;
	cout << ret << endl;
}