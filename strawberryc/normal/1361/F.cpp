#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;
typedef tree <int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ds;

const int N = 2e5 + 5, M = N << 1, E = 20;

int n, p[N], w[N], len, a[M], RMQ[M][E], Log[M] = {-1}, lc[M], rc[M], fa[M], Root, q;
ds s[M];
ll inv[M], f[M];

int query(int l, int r)
{
	int k = Log[r - l + 1];
	return a[RMQ[l][k]] < a[RMQ[r - (1 << k) + 1][k]]
		? RMQ[l][k] : RMQ[r - (1 << k) + 1][k];
}

int build(int l, int r)
{
	int u = query(l, r); if (l == r) return u;
	fa[lc[u] = build(l, u - 1)] = u;
	fa[rc[u] = build(u + 1, r)] = u;
	return u;
}

void orz(int u, int val, int sgn)
{
	u = (u << 1) - 1; int v = u; u = fa[u];
	if (sgn < 0) s[v].erase(val); else s[v].insert(val);
	for (; u; u = fa[u], v = fa[v])
	{
		if (lc[u] == v) inv[u] += sgn * (int) (s[rc[u]].order_of_key(val));
		else inv[u] += sgn * ((int) (s[lc[u]].size() - s[lc[u]].order_of_key(val)));
		f[u] = f[lc[u]] + f[rc[u]] + Min(inv[u],
			(ll) (1ll * s[lc[u]].size() * s[rc[u]].size()) - inv[u]);
		if (sgn < 0) s[u].erase(val); else s[u].insert(val);
	}
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i <= n; i++) read(p[i]);
	for (int i = 1; i < n; i++) read(w[i]);
	len = (n << 1) - 1;
	for (int i = 1; i <= len; i++) Log[i] = Log[i >> 1] + 1,
		a[i] = i & 1 ? n : w[i >> 1], RMQ[i][0] = i;
	for (int j = 1; j <= 18; j++)
		for (int i = 1; i + (1 << j) - 1 <= len; i++)
			RMQ[i][j] = a[RMQ[i][j - 1]] < a[RMQ[i + (1 << j - 1)][j - 1]]
				? RMQ[i][j - 1] : RMQ[i + (1 << j - 1)][j - 1];
	Root = build(1, len);
	for (int i = 1; i <= n; i++) orz(i, p[i], 1);
	read(q);
	while (q--) read(x), read(y), orz(x, p[x], -1), orz(y, p[y], -1),
		std::swap(p[x], p[y]), orz(x, p[x], 1), orz(y, p[y], 1),
			printf("%lld\n", f[Root]);
	return 0;
}