#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> v;
	v.push_back(a[0]);
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] < a[i - 1] && a[i] < a[i + 1] || a[i] > a[i - 1] && a[i] > a[i + 1]) v.push_back(a[i]);
	}
	v.push_back(a[n - 1]);
	cout << v.size() << '\n';
	for (int i: v) cout << i << ' ';
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