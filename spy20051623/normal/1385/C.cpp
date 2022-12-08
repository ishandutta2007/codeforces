#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int p = n - 1;
	while (p > 0 && a[p] <= a[p - 1]) --p;
	while (p > 0 && a[p] >= a[p - 1]) --p;
	cout << p << '\n';
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