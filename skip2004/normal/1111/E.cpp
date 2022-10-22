#include<bits/stdc++.h>
const int maxn = 100100;
const int mod = 1e9 + 7;
using std::cin;
using std::cout;
using u32 = unsigned;
using ll = long long;
int n, q;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int st[20][maxn], dfn[maxn], size[maxn], tot;
const int M = 500;
int C[M][M], ifac[maxn], inv[maxn];
inline int min(int x, int y) {
	return dfn[x] < dfn[y] ? x : y;
}
inline int cmp0(int x, int y) {
	return dfn[x] < dfn[y];
}
inline int lca(int x, int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x != y ? min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]) : x;
}
inline int insub(int x, int y) {
	return u32(dfn[x] - dfn[y]) < (u32) size[y];
}
inline void dfs0(int x, int fa = 0) {
	st[0][tot] = fa, dfn[x] = ++ tot, size[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
	}
}
int is[maxn];
namespace vt {
	struct T {
		int to, nxt;
	} way[maxn << 1];
	int h[maxn], num;
	inline void link(int x, int y) {
		way[++num] = {y, h[x]}, h[x] = num;
		way[++num] = {x, h[y]}, h[y] = num;
	}
	int dp[maxn][310], size[maxn];
	inline void dfs0(int x, int m, int fa = 0) {
		for(int i = 0;i <= m;++i) dp[x][i] = 1;
		for(int & i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
			dfs0(way[i].to, m, x);
			int * a = dp[x], *to = dp[way[i].to];
			for(int i = 0;i <= m;++i) a[i] = (ll) a[i] * to[i] % mod;
		}
		if(is[x]) {
			for(int i = m;i >= 1;--i) dp[x][i] = (ll) dp[x][i - 1] * i % mod;
			dp[x][0] = 0;
		}
	}
	inline int get(int * a, int m) {
		ll res = 0;
		for(int i = 0;i <= m;++i) {
			for(int j = 0;j < i;++j) {
				a[i] = (a[i] + ll(mod - C[i][j]) * a[j]) % mod;
			}
			res = (res + (ll) a[i] * ifac[i]) % mod;
		}
		return res % mod;
	}
}
int main() {
	for(int i = 0;i < M;++i) {
		for(int j = C[i][0] = 1;j < M;++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	*ifac = ifac[1] = inv[1] = 1;
	for(int i = 2;i < M;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y);
	}
	dfs0(1);
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 < n;++j) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	for(int i = 1, k, m, r;i <= q;++i) {
		static std::vector<int> vec;
		cin >> k >> m >> r, vec.resize(k);
		for(int & x : vec) cin >> x, is[x] = 1;
		vec.push_back(r);
		sort(vec.begin(), vec.end(), cmp0);
		for(int size = vec.size(), i = 0;i + 1 < size;++i) {
			vec.push_back(lca(vec[i], vec[i + 1]));
		}
		sort(vec.begin(), vec.end(), cmp0);
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		static int st[maxn]; int top = 0;
		for(int x : vec) {
			for(;top && !insub(x, st[top]);) -- top;
			if(top != 0) vt::link(st[top], x);
			st[++top] = x;
		}
		vt::dfs0(r, m);
		cout << vt::get(vt::dp[r], m) << '\n';
		vt::num = 0;
		for(int & x : vec) is[x] = 0;
	}

}