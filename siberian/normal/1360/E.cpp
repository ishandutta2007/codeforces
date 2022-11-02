#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	vector<vector<char>> a(n, vector<char> (n, ' '));
	for (auto &i : a) for (auto &j : i) cin >> j;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1) continue;
			if (j == n - 1) continue;
			if (a[i][j] == '0') continue;
			if (a[i][j + 1] == '1') continue;
			if (a[i + 1][j] == '1') continue;
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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