// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) (1 << 18), mod = (int) 998244353;

int pw(int a, int b) { return b == 0 ? 1 : (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod; }
int a[20][N], b[N], c[N], d[N], f[N], inv[N];
int comb(int n, int r) {
	if (n == r) return 1;
	if (n - r < 0 || r < 0 || n < 0) return 0;
	return f[n] * (LL) inv[r] % mod * inv[n - r] % mod;
}
void NTT(int a[], bool inverse, int lg) {
	int n = 1 << lg;
	for (int i = 0; i < n; ++i) {
		int rev = 0;
		for (int j = 0; j < lg; ++j) if (i >> j & 1) rev += 1 << (lg - j - 1);
		if (rev > i)
			swap(a[rev], a[i]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		int wn = pw(3, (mod - 1) / len);
		if (inverse)
			wn = pw(wn, mod - 2);
		for (int j = 0; j < n; j += len) {
			int w = 1;
			for (int x = j, y = j + len / 2, id = 0; y < j + len; ++x, ++y, ++id) {
				int u = a[x], v = (LL) a[y] * w % mod;
				a[x] = u + v; 
				a[y] = u - v + mod;
				while (a[x] >= mod)
					a[x] -= mod;
				while (a[y] >= mod)
					a[y] -= mod;
				w = (LL) w * wn % mod;
			}
		}
	}
	if (inverse) {
		int div = pw(n, mod - 2);
		for (int i = 0; i < n; ++i)
			a[i] = (LL) a[i] * div % mod;
	}
}
void solve(int n, int h) {
	if (n == 0) {
		a[h][0] = 1;
		return;
	}
	solve(n >> 1, h + 1);
	for (int i = 0; i < (1 << 18 - h); ++i) b[i] = c[i] = d[i] = 0;
	int m = n >> 1;
	for (int i = 0; i <= m; ++i) c[i] = a[h + 1][i] * (LL) f[m - i] % mod;
	for (int i = 0; i <= m; ++i) d[i] = inv[i] * (LL) pw(m, i) % mod;
	NTT(c, false, 18 - h);
	NTT(d, false, 18 - h);
	for (int i = 0; i < (1 << 18 - h); ++i) b[i] = (LL) c[i] * d[i] % mod;
	NTT(b, true, 18 - h);
	for (int i = m + 1; i < (1 << 18 - h); ++i) b[i] = 0;
	for (int i = 0; i <= m; ++i) b[i] = (LL) b[i] * inv[m - i] % mod;
	//			b[i + j] = (b[i + j] + a[h + 1][i] * (LL) comb(m - i, j) % mod * pw(m, j)) % mod;
	NTT(b, false, 18 - h);
	for (int i = 0; i < (1 << 18 - h); ++i) c[i] = 0;
	for (int i = 0; i <= m; ++i) c[i] = a[h + 1][i];
	NTT(c, false, 18 - h);
	for (int i = 0; i < (1 << 18 - h); ++i) a[h][i] = c[i] * (LL) b[i] % mod;
	NTT(a[h], true, 18 - h);	
	
	if (n & 1) {
		for (int use = n; use >= 0; --use) {
			a[h][use] = ((use != 0 ? a[h][use - 1] * (LL) (n - 1) : 0) + a[h][use]) % mod;
		}
	}
}
int main() {
	for (int j = 0; j < N; ++j) f[j] = (j == 0 ? 1 : f[j - 1] * (LL) j % mod), inv[j] = pw(f[j], mod - 2);
	int n, a, b;
	cin >> n >> a >> b;
	/*
	{
	   dp[0][0] = 1;
	   for (int j = 1; j <= n; ++j) {
	   for (int used = 0; used <= j; ++used) {
	   dp[j][used] = (dp[j][used] + (LL) dp[j - 1][used] * (j - 1) + (used >= 1 ? dp[j - 1][used - 1] : 0)) % mod;
	   }
	   }
	   --a, --b;
	   int comb = 1;
	   for (int i = 1; i <= a; ++i)
		  comb = (LL) comb * (a + b - i + 1) % mod, comb = (LL) comb * pw(i, mod - 2) % mod;
	   cout << (LL) comb * dp[n - 1][a + b] % mod  << endl;
	//   for (int k = 0; k <= n; ++k)
	  // cout << dp[n][k] << ", ";
	}
	*/
	--a, --b;
	if (a < 0 || b < 0) {
		cout << 0 << endl;
		return 0;
	}
	if (a + b > n) {
		cout << 0 << endl;
		return 0;
	}
	n -= 1;
	solve(n, 0);
	int res = ::a[0][n - (a + b)];
	for (int i = 1; i <= a; ++i)
		res = (LL) res * (a + b - i + 1) % mod, res = res * (LL) pw(i, mod - 2) % mod;
	cout << res << endl;
}