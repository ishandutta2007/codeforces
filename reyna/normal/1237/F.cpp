
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

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 4005, mod = (int) 998244353;

int f[N], inv[N], banr[N], banw[N], dpr[N][3], dpw[N][3];
int comb(int n, int r) {
	if (n == r) return 1;
	if (r < 0 || n < 0 || n - r < 0) return 0;
	return f[n] * (LL) inv[r] % mod * inv[n - r] % mod;
}
int pw(int a, int b) {
	if (b == 0) return 1;
	return (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod;
}
int main() {
	inv[0] = f[0] = 1;
	for (int j = 1; j < N; ++j)
		f[j] = (LL) f[j - 1] * j % mod, inv[j] = pw(f[j], mod - 2);
	int n, m, q;
	cin >> n >> m >> q;
	while (q--) {
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		--x0, --y0, --x1, --y1;
		banr[x0] = banr[x1] = 1;
		banw[y0] = banw[y1] = 1;
	}
	dpr[0][2] = 1;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < N; ++i) dpr[i][0] = dpr[i][1], dpr[i][1] = dpr[i][2], dpr[i][2] = 0;
		for (int i = 0; i <= n; ++i) {
			dpr[i][2] = dpr[i][1];
			if (j > 0 && i > 0 && !banr[j] && !banr[j - 1]) {
				dpr[i][2] = (dpr[i][2] + dpr[i - 1][0]) % mod;
			}
		}
	}
	dpw[0][2] = 1;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < N; ++i) dpw[i][0] = dpw[i][1], dpw[i][1] = dpw[i][2], dpw[i][2] = 0;
		for (int i = 0; i <= m; ++i) {
			dpw[i][2] = dpw[i][1];
			if (j > 0 && i > 0 && !banw[j] && !banw[j - 1]) {
				dpw[i][2] = (dpw[i][2] + dpw[i - 1][0]) % mod;
			}
		}
	}
	int haver = 0, havew = 0;
	for (int j = 0; j < n; ++j)
		haver += !banr[j];
	for (int j = 0; j < m; ++j)
		havew += !banw[j];
	int res = 0;
	for (int user = 0; user * 2 <= haver; ++user) {
		for (int usew = 0; usew * 2 <= havew; ++usew) {
			int ways = (LL) dpr[user][2] * dpw[usew][2] % mod;
			if (!ways) continue;
			int remr = haver - user * 2;
			int remw = havew - usew * 2;
			if (user > remw || usew > remr) continue;
			ways = (LL) ways * comb(remw, user) % mod * f[user] % mod * comb(remr, usew) % mod * f[usew] % mod;
			res = (res + ways) % mod;
		}
	}
	cout << res << '\n';
}