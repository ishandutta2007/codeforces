#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> k;
	vector<int> b(k);
	for (int i = 0; i < k; ++i) {
		cin >> b[i];
	}
	vector<pair<int, int>> aa, bb;
	for (int i = 0; i < n; ++i) {
		int x = a[i], y = 1;
		while (x % m == 0) {
			x /= m;
			y *= m;
		}
		if (aa.empty() || aa.back().first != x) aa.emplace_back(x, y);
		else aa.back().second += y;
	}
	for (int i = 0; i < k; ++i) {
		int x = b[i], y = 1;
		while (x % m == 0) {
			x /= m;
			y *= m;
		}
		if (bb.empty() || bb.back().first != x) bb.emplace_back(x, y);
		else bb.back().second += y;
	}
	if (aa == bb) cout << "YES\n";
	else cout << "NO\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}