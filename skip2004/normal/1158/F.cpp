#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 3030;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int dp[maxn][maxn];
int a[maxn];
int n, c;
inline void reduce(int & x) {
	x += x >> 31 & mod;
}
namespace naive {
	const int N = 10;
	typedef int AI[1 << N][maxn];
	AI dp;
	inline void naive() {
		const int m = n / c;
		dp[0][0] = 1;
		for(int i = 1;i <= n;++i) {
			for(int j = (1 << c) - 1;j >= 0;--j) {
				int * B = dp[j | 1 << a[i] - 1];
				for(int k = 0;k <= m;++k) {
					reduce(B[k] += dp[j][k] - mod);
				}
			}
			for(int j = 0;j <= m;++j) {
				dp[0][j + 1] = (dp[0][j + 1] + dp[(1 << c) - 1][j]) % mod;
				dp[(1 << c) - 1][j] = 0;
			}
		}
		for(int i = 0;i <= n;++i) {
			ll s = i ? 0 : mod - 1;
			for(int j = 0;j < 1 << c;++j) {
				s += dp[j][i];
			}
			cout << s % mod << ' ';
		}
		cout.put(10);
	}
}
namespace smart {
	int dp[maxn][maxn];
	int g[maxn][maxn];
	int cnt[maxn], pw[maxn];
	int inv[maxn];
	int can[maxn];
	inline void smart() {
		inv[0] = pw[0] = 1;
		for(int i = 1;i < maxn;++i) {
			pw[i] = pw[i - 1] * 2 % mod;
			inv[i] = inverse(pw[i] - 1);
		}
		rep(i, 1, n) {
			memset(cnt, 0, sizeof cnt);
			int mul = 1, ct = 0;
			rep(j, i, n) {
				mul = (ll) mul * inv[cnt[a[j]]] % mod;
				ct += ++ cnt[a[j]] == 1;
				if(ct == c) g[i][j] = mul;
				mul = (ll) mul * (pw[cnt[a[j]]] - 1) % mod;
			}
		}
		dp[0][0] = 1;
		const int m = n / c;
		for(int i = 0;i < n;++i) {
			for(int j = 0;j <= m;++j) if(dp[i][j]) {
				for(int k = i + 1;k <= n;++k) {
					dp[k][j + 1] = (dp[k][j + 1] + (ll) dp[i][j] * g[i + 1][k]) % mod;
				}
			}
		}
		rep(i, 1, n) {
			rep(j, i, n) {
				reduce(g[i][j] += g[i][j - 1] - mod);
			}
		}
		memset(cnt, 0, sizeof cnt);
		can[n + 1] = 1;
		for(int i = n;i >= 1;--i) {
			++ cnt[a[i]], can[i] = 1;
			rep(k, 1, c) can[i] = (ll) can[i] * (pw[cnt[k]] - 1) % mod;
			reduce(can[i] = pw[n - i + 1] - can[i]);
		}
		rep(i, 0, n) {
			ll s = i ? 0 : mod - 1;
			rep(j, 0, n) {
				s = (s + (ll) dp[j][i] * can[j + 1]) % mod;
			}
			cout << s % mod << ' ';
		}
		cout.put(10);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> c;
	std::mt19937 rd(time(0));
	rep(i, 1, n) {
		cin >> a[i];
	}
	c <= 10 ? naive::naive() : smart::smart();
}