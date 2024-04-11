#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 4050;
typedef unsigned long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n1, n2, k;
struct block {
	static const int N = 4000;
	ll a[N], test;
	inline void add(const block & b) {
		if(test + b.test >= mod) {
			for(int i = 0;i < N;++i) {
				a[i + 0] = (b.a[i + 0] + a[i + 0]) % mod;
			}
			test = 1;
		} else {
			for(int i = 0;i < N;++i) {
				a[i + 0] += b.a[i + 0];
			}
			test += b.test;
		}
	}
	inline void eql(const block & b, const block & c) {
		if(b.test + c.test >= mod) {
			for(int i = 0;i < N;++i) {
				a[i + 0] = (b.a[i + 0] + c.a[i + 0]) % mod;
			}
			test = 1;
		} else {
			for(int i = 0;i < N;++i) {
				a[i + 0] = b.a[i + 0] + c.a[i + 0];
			}
			test = b.test + c.test;
		}
	}
};
block dp[2][maxn], E;
size_t Time = 0;
struct T {
	int u[maxn], v[maxn], g[maxn];
	std::vector<int> vc[maxn];
	inline void init(int n) {
		for(int i = 1;i < n;++i) {
			cin >> u[i] >> v[i];
			-- u[i], -- v[i];
			vc[u[i]].push_back(v[i]);
			vc[v[i]].push_back(u[i]);
		}
		for(int i = 0;i < n;++i) {
			dp[0][i] = E;
			dp[0][i].a[i] = 1;
			dp[0][i].test = 1;
		}
		g[0] = n;
		for(int i = 1;i <= k;++i) {
			block * a = dp[i & 1], * b = dp[i + 1 & 1];
			for(int j = 0;j < n;++j) {
				if(vc[j].size() == 1) {
					a[j] = b[vc[j].back()];
				} else {
					a[j].eql(b[vc[j][0]], b[vc[j][1]]);
					for(int i = 2;i < vc[j].size();++i) {
						a[j].add(b[vc[j][i]]);
					}
				}
			}
			for(int j = 0;j < n;++j) {
				g[i] = (g[i] + a[j].a[j]) % mod;
			}
		}
	}
} T1, T2;
int fac[maxn], ifac[maxn], inv[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n1 >> n2 >> k;
	T1.init(n1);
	T2.init(n2);
	fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxn;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	int ans = 0;
	for(int i = 0;i <= k;++i) {
		ans = (ans + (ll) T1.g[i] * T2.g[k - i] % mod * ifac[i] % mod * ifac[k - i]) % mod;
	}
	cout << (ll) ans * fac[k] % mod << '\n';
}