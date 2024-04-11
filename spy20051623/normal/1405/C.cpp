#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i + k <= n; ++i) {
		if (s[i] != '?' && s[i + k] == '?') s[i + k] = s[i];
	}
	for (int i = n; i - k >= 1; --i) {
		if (s[i] != '?' && s[i - k] == '?') s[i - k] = s[i];
	}
	for (int i = 1; i < n - k + 1; ++i) {
		if (s[i] != '?' && s[i + k] != '?' && s[i] != s[i + k]) {
			cout << "NO\n";
			return;
		}
	}
	vector<int> x(n + 1), y(n + 1);
	for (int i = 1; i <= n; ++i) {
		x[i] = x[i - 1] + (s[i] == '0'), y[i] = y[i - 1] + (s[i] == '1');
	}
	for (int i = 1; i <= n - k + 1; ++i) {
		if (x[i + k - 1] - x[i - 1] > k / 2 || y[i + k - 1] - y[i - 1] > k / 2) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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