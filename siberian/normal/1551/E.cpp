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

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	// vin(a);
	for (auto& i : a) cin >> i;
	for (auto& i : a) --i;
	vector<vector<int>> dp(n + 1, vector<int>(n, (int)-1e9));

	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int cnt = 0; cnt < n; ++cnt) {
			if (dp[i][cnt] < 0) continue;
			chkmax(dp[i + 1][cnt], dp[i][cnt] + (a[i] == i - cnt));
			if (cnt + 1 < n) {
				chkmax(dp[i + 1][cnt + 1], dp[i][cnt]);
			}
		}
	}
	
	int ans = n;
	for (int cnt = 0; cnt < n; ++cnt) {
		if (dp[n][cnt] >= k) {
			chkmin(ans, cnt);
		}
	}
	if (ans == n) ans = -1;
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}