#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> ans(n, vector<int> (m, 0));
	vector<pair<int, int>> cnt;
	for (int i = 0; i < n; i++) {
		cnt.push_back({a, i});
	}
	for (int j = 0; j < m; j++) {
		sort(all(cnt));
		reverse(all(cnt));
		for (int i = 0; i < b; i++) {
			ans[cnt[i].second][j] = 1;
			cnt[i].first--;
		}
	}
	sort(all(cnt));
	if (cnt[0].first != 0 || cnt[n - 1].first != 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (auto i : ans) {
			for (auto j : i) {
				cout << j;
			}
			cout << "\n";
		}
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