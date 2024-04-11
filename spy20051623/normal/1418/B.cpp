#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		if (!b[i]) v.push_back(a[i]);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0, p = 0; i < n; ++i) {
		if (!b[i]) a[i] = v[p++];
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