#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	sort(all(a));
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		if (a[i] <= i + 1) dp[i] = 1;
		if (i - a[i] >= 0) chkmax(dp[i], dp[i - a[i]] + 1);
	}
	cout << *max_element(all(dp)) << "\n";
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