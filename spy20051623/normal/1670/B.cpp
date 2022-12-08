#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	vector<int> v(26);
	for (int i = 0; i < k; ++i) {
		char c;
		cin >> c;
		v[c - 'a'] = 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (v[s[i] - 'a']) {
			int p = i - 1, c = 0;
			while (p >= 0 && !v[s[p] - 'a']) ++c, --p;
			ans = max(ans, c + (p >= 0));
		}
	}
	cout << ans << "\n";
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