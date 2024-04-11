#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m, 0));
	for (auto &i : a) for (auto &j : i) cin >> j;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int now = 0;
			now += i > 0;
			now += i + 1 < n;
			now += j > 0;
			now += j + 1 < m;
			if (a[i][j] > now) {
				cout << "NO\n";
				return;
			}
			a[i][j] = now;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
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