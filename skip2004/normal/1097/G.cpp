#include<bits/stdc++.h>
const int maxn = 100100, maxk = 210;
const int mod = 1e9 + 7;
using std::cin;
using std::cout;

int c[maxk + maxk][maxk + maxk];
int n, k;

typedef long long ll;
int fac[maxk], inv[maxk], ifac[maxk];
inline void reduce(int & x) { x += x >> 31 & mod; }
inline void add(int & x, int y) { x += y - mod, x += x >> 31 & mod; }
inline void sub(int & x, int y) { x -= y, x += x >> 31 & mod; }
inline void fam(int & x, int y, int z) { x = (x + (ll) y * z) % mod; }
struct poly {
	int a[maxk];
	inline void add(int size) {
		for(int i = 0, mul = 1;i <= k;++i) {
			::add(a[i], mul);
			mul = (ll) mul * size % mod;
		}
	}
};

const poly EP = poly {};
inline void add(poly & x, const poly & y) {
	for(int i = 0;i <= k;++i) {
		add(x.a[i], y.a[i]);
	}
}
inline void sub(poly & x, const poly & y) {
	for(int i = 0;i <= k;++i) {
		sub(x.a[i], y.a[i]);
	}
}
inline int deg(const poly & x) {
	int dg = k;
	for(;dg && !x.a[dg];)
		-- dg;
	return dg;
}
inline int neiji(int * a, int * b, int len) {
	typedef unsigned long long u64;
	u64 ans = 0;
	int i = 0;
#define wwj(x) (u64) a[i + x] * b[-(i + x)]
	for(;i + 15 < len;i += 16) {
		ans = (ans
		+ wwj(0) + wwj(1) + wwj(2) + wwj(3)
		+ wwj(4) + wwj(5) + wwj(6) + wwj(7)
		+ wwj(8) + wwj(9) + wwj(10) + wwj(11)
		+ wwj(12) + wwj(13) + wwj(14) + wwj(15)) % mod;
	}
	for(;i < len;++i) ans += wwj(0);
	return ans % mod;
}
inline void multi(poly & x, poly y) {
	int dx = deg(x), dy = deg(y);
	for(int i = 0;i <= dx;++i) x.a[i] = (ll) x.a[i] * ifac[i] % mod;
	for(int i = 0;i <= dy;++i) y.a[i] = (ll) y.a[i] * ifac[i] % mod;
	for(int i = std::min(k, dx + dy);i >= 0;--i) {
		const int li = std::max(i - dy, 0), ri = std::min(i, dx);
		x.a[i] = (ll) neiji(x.a + li, y.a + i - li, ri - li + 1) * fac[i] % mod;
	}
}

struct edge {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
poly zero, one;
poly dp[maxn], ans;
inline void dfs0(int x, int fa = 0) {
	dp[x] = zero;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		multi(dp[x], dp[way[i].to]);
	}
	add(ans, dp[x]);
	add(ans, dp[x]);
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		sub(ans, dp[way[i].to]);
	}
	multi(dp[x], one);

	add(dp[x], dp[x]);
	sub(dp[x], one);
	add(dp[x], zero);
}
int main() {
	// freopen("1.in", "r", stdin);
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxk;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	for(int i = 0;i < maxk + maxk;++i) {
		for(int j = c[i][0] = 1;j <= i;++j) {
			reduce(c[i][j] = c[i - 1][j] + c[i - 1][j - 1] - mod);
		}
	}
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y);
	}
	zero.add(0);
	one.add(1);
	dfs0(1);
	cout << ans.a[k] << '\n';
}