#include <bits/stdc++.h>

using namespace std;

int u[1000], v[1000];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> u[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		a = max(a, min(u[i], v[i]));
		b = max(b, max(u[i], v[i]));
	}
	cout << a * b << '\n';
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