#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m, 0));
	for (auto &i : a) {
		for (auto &j : i) {
			cin >> j;
		}
	}
	vector<int> cnt0(n + m, 0), cnt1(n + m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt0[i + j] += a[i][j] == 0;
			cnt1[i + j] += a[i][j] == 1;
		}
	}
	int ans = 0;
	for (int sum = 0; sum < n - 1 + m - 1 - sum; sum++) {
		ans += min(cnt0[sum] + cnt0[n - 1 + m - 1 - sum], cnt1[sum] + cnt1[n - 1 + m - 1 - sum]);
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}