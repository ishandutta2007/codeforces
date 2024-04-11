#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

const int N = 2e5 + 10, K = 17;
int n, k;
string s;
int pref[N][K + 1];

void precalc() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			pref[i][j] = 0;
			if (i > 0) pref[i][j] += pref[i - 1][j];
		}
		if (s[i] != '?') pref[i][s[i] - 'a']++;
		else pref[i][k]++;
	}
}

int getPref(int l, int r, int id) {
	return pref[r][id] - (l > 0 ? pref[l - 1][id] : 0);
}

int dp[1 << K];

int nxt[N][K];

void buildNxt(int len) {
	for (int pos = n - 1; pos >= 0; --pos) {
		for (int a = 0; a < k; ++a) {
			nxt[pos][a] = n + 1;
			if (pos < n - 1) nxt[pos][a] = nxt[pos + 1][a];
			if (pos + len - 1 < n) {
				if (getPref(pos, pos + len - 1, a) + getPref(pos, pos + len - 1, k) == len) {
					nxt[pos][a] = pos + len;
				}
			}
		}
	}
}

void calcDp() {
	fill(dp, dp + (1 << k), n + 1);
	dp[0] = 0;
	for (int mask = 0; mask < (1 << k); ++mask) {
		if (dp[mask] >= n) continue;
		for (int nxtBit = 0; nxtBit < k; ++nxtBit) {
			if ((mask >> nxtBit) & 1) continue;
			chkmin(dp[mask ^ (1 << nxtBit)], nxt[dp[mask]][nxtBit]);
		}
	}
}

bool check(int len) {
	buildNxt(len);
	calcDp();
	return dp[(1 << k) - 1] <= n;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	cin >> n >> k;
	cin >> s;
	precalc();
	// cerr << check(4) << endl;
	// exit(0);
	int l = 0, r = n / k + 1;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (check(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l << endl;
	return 0;
}