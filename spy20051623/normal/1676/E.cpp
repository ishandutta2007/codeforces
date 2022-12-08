#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), s(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end(), greater<int>());
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	while (m--) {
		int x;
		cin >> x;
		auto it = lower_bound(s.begin(), s.end(), x);
		if (it == s.end()) cout << "-1\n";
		else cout << it - s.begin() << '\n';
	}
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