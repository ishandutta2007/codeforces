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

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = 1e5 + 5, sq = 300, mod = 1e9 + 7;

int pw(int a, int b) { return b? 1ll * pw(a * 1ll * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }

int f[N], inv[N], res[N], ans[sq][N], p25[N], p26[N];

int comb(int n, int k) {
	if (k > n) return 0;
	return f[n] * 1ll * inv[k] % mod * inv[n - k] % mod;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = inv[0] = p25[0] = p26[0] = 1;
	rep(i, N - 1) f[i + 1] = f[i] * 1ll * (i + 1) % mod, inv[i + 1] = pw(f[i + 1], mod - 2), p25[i + 1] = p25[i] * 1ll * 25 % mod, p26[i + 1] = p26[i] * 1ll * 26 % mod;
	rep(k, sq) if (k)
		for (int n = k; n < N; ++n) {
			ans[k][n] = (ans[k][n - 1] * 1ll * 26 % mod + comb(n - 1, k - 1) * 1ll * p25[n - k]) % mod; 
		}
	int q;
	cin >> q;
	string s;
	for (int tt = 0; tt < q + 1; ++tt) {
		int c = 1;
		if (tt)
			cin >> c;
		if (c == 1) {
			cin >> s;
			int k = (int) s.size();
			if (k >= sq) {
				memset(res, 0, sizeof res);
				for (int n = k; n < N; ++n) {
					res[n] = (res[n - 1] * 1ll * 26 % mod + comb(n - 1, k - 1) * 1ll * p25[n - k]) % mod;
				}
			}
		} else {
			int n;
			cin >> n;
			int k = (int) s.size();
			if (n < k) {
				cout << 0 << '\n';
				continue;
			}
			if (k < sq) {
				cout << ans[k][n] << '\n';
			} else {
				cout << res[n] << '\n';
			}
		}
	}
	return 0;
}