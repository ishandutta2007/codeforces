#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
long long a[N], b[N], c[N];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	b[0] = -1e18;
	for (int i = 1; i <= n; ++i) {
		b[i] = max(b[i - 1], c[i - 1] + a[i]);
		c[i] = max(c[i - 1], b[i - 1] - a[i]);
	}
	cout << b[n] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}