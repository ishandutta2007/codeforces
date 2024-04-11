#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int ans = 2e9;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int d = 0;
			for (int k = 0; k < m; ++k) {
				int x = abs(int(s[i][k]) - int(s[j][k]));
//				d += min(x, 26 - x);
				d += x;
			}
			ans = min(ans, d);
		}
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}