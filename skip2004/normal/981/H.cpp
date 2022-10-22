#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1 << 19;
const int mod = 998244353;
const int inv2 = (mod + 1) >> 1;
typedef long long ll;
inline int pow(int a,int b,int ans = 1) {
	for(;b;b >>= 1,a = (ll) a * a % mod) if(b & 1)
		ans = (ll) ans * a % mod;
	return ans;
}
inline void reduce(int & x){ x += x >> 31 & mod; }
typedef int AI[maxn];
namespace poly {
	AI wn, rev;
	int lim,invlim;
	inline void init_() {
		for(int mid = 1;mid < 1 << 19;mid <<= 1) {
			const int W = pow(3, mod / mid / 2); wn[mid] = 1;
			for(int i = 1;i < mid;++i) wn[mid + i] = (ll) wn[mid + i - 1] * W % mod;
		}
	}
	inline void init(int len) {
		for(lim = invlim = 1;lim < len;lim <<= 1) invlim = (ll) invlim * inv2 % mod;
		for(int i = 1;i < lim;++i) rev[i] = rev[i >> 1] >> 1 | (i % 2 * lim / 2);
	}
	inline void fft(int * a,int type) {
		typedef unsigned long long ll;
		static ll t[maxn];
		for(int i = 0;i < lim;++i) t[i] = a[rev[i]];
		for(int mid = 1;mid < lim;mid <<= 1) for(int i = 0;i < lim;i += mid + mid) for(int j = 0;j < mid;++j) {
			const int x = (ll) t[i + j + mid] * wn[mid + j] % mod;
			t[i + j + mid] = mod - x + t[i + j]; t[i + j] += x;
		}
		for(int i = 0;i < lim;++i) a[i] = t[i] % mod;
		if(!type) {
			for(int i = 0;i < lim;++i) a[i] = (ll) a[i] * invlim % mod;
			std::reverse(a + 1,a + lim);
		}
	}
	inline std::vector<int> conv(std::vector<int> v0, std::vector<int> v1) {
		init(v0.size() + v1.size() - 1); 
		static int A[maxn], B[maxn];
		for(int i = 0;i < (int) v0.size();++i) A[i] = v0[i];
		for(int i = v0.size();i < lim;++i) A[i] = 0;
		for(int i = 0;i < (int) v1.size();++i) B[i] = v1[i];
		for(int i = v1.size();i < lim;++i) B[i] = 0;
		fft(A, 1), fft(B, 1);
		for(int i = 0;i < lim;++i) A[i] = (ll) A[i] * B[i] % mod;
		fft(A, 0);
		return std::vector<int>(A, A + v0.size() + v1.size() - 1);
	}
	int a[maxn];
	inline std::vector<int> solve(int l, int r) {
		if(l + 1 == r) return {1, a[l]};
		int mid = l + r >> 1;
		return conv(solve(l, mid), solve(mid, r));
	}
	inline std::vector<int> get(std::vector<int> v) {
		for(int i = 0;i < (int) v.size();++i) a[i] = v[i];
		return solve(0, v.size());
	}
}
int n, k;
struct T {
	int to, nxt;
} way[maxn << 1];
int h[maxn], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int size[maxn];
int fac[maxn], ifac[maxn], inv[maxn];
std::vector<int> g[maxn];
std::map<int, int> val[maxn];
inline int calc(int x, int size) {
	if(val[x].count(size)) return val[x][size];
	static int g0[maxn];
	const int N = g[x].size();
	int & ans = val[x][size] = ifac[k];
	g0[0] = g[x][0];
	for(int i = 1;i + 1 < N && i <= k;++i) {
		g0[i] = (g[x][i] + ll(mod - g0[i - 1]) * size) % mod;
		ans = (ans + (ll) g0[i] * ifac[k - i]) % mod;
	}
	return ans = (ll) ans * fac[k] % mod;
}
inline void dfs0(int x, int fa = 0) {
	size[x] = 1;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
		size[x] += size[way[i].to];
		g[x].push_back(size[way[i].to]);
	}
	g[x].push_back(n - size[x]);
	g[x] = poly::get(g[x]);
}
int dp[maxn], sum[maxn];
int ans;
inline void dfs1(int x, int fa = 0) {
	dp[x] = calc(x, n - size[x]);
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs1(way[i].to, x);
		ans = (ans + (ll) sum[way[i].to] * calc(x, size[way[i].to])) % mod;
		ans = (ans + (ll) sum[way[i].to] * sum[x]) % mod;
		reduce(sum[x] += sum[way[i].to] - mod);
	}
	reduce(sum[x] += dp[x] - mod);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxn;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	poly::init_();
	cin >> n >> k;
	if(k == 1) {
		cout << (ll) n * (n - 1) / 2 % mod << '\n';
		return 0;
	}
	for(int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		link(x, y);
	}
	dfs0(1, 0);
	dfs1(1, 0);
	cout << ans << '\n';
}