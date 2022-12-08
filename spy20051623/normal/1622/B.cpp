#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	string s;
	cin >> s;
	map<int, int> m, mm;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') m[a[i]];
		else mm[a[i]];
	}
	int cur = 0;
	for (auto &i: m) i.second = ++cur;
	for (auto &i: mm) i.second = ++cur;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') a[i] = m[a[i]];
		else a[i] = mm[a[i]];
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}