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

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = (int) 130 + 6, mod = 1ll << 32;

int n, p, q, dp[N][N], ca[N][N], comb[N], c[N][N], a[N], b[N], sm[N];

void init() {
	for (int i = 0; i <= p; ++i) {
		int m = n - p + i;
		for (int r = 0; r <= min(p, m); ++r) {
			if (r > m || m < 0)
				continue;
			for (int j = 0; j < r; ++j)
				a[j] = j + 1, b[j] = m - j;
			for (int k = 2; k <= r; ++k) {
				int cnt = 0;
				for (int j = 0; j < r; ++j)
					while (a[j] % k == 0)
						a[j] /= k, cnt++;
				for (int j = 0; j < r; ++j)
					while (cnt && b[j] % k == 0)
						b[j] /= k, cnt--;
			}
			int res = 1;
			rep(j, r)
				res = (res * b[j]) % mod;
			c[i][r] = res;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> p >> q;
	p = min(p, n - 1);
	init();
	for (int i = 0; i <= p; ++i)
		dp[0][i] = 1;
	for (int i = 1; i <= p; ++i)
		for (int j = 1; j <= p; ++j) {
			for (int k = 0; k < j; ++k)
				dp[i][j] = (dp[i][j] + c[j][j - k] * dp[i - 1][k]) % mod;
//			cout << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	/*
	for (int i = 0; i <= q; ++i)
		for (int j = 0; j <= p; ++j)
			if (i == j || j == 0)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	*/
	int res = 0;
	comb[0] = 1;
	for (int i = 1; i <= q; ++i) {
		for (int j = min(p, i); j >= 0; --j) {
			if (i == j || j == 0)
				comb[j] = 1;
			else
				comb[j] = (comb[j] + comb[j - 1]) % mod;
		}
		int sum = 0;
		for (int j = 0; j <= p; ++j)
			sum = (sum + dp[j][p] * comb[j]) % mod;
//		cout << sum << endl;
//		cout << sum << endl;
		res ^= i * sum % mod;
		res %= mod;
//		res %= mod;
	}
	res %= mod;
	while (res < 0) res += mod;
	while (res >= mod) res -= mod;
	cout << res << endl;
	return 0;
}