#include <bits/stdc++.h>

using namespace std;

long long v[1000005];

void solve() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x] = max(v[x], 1ll * y * z);
	}
	for (int i = 1; i <= c; ++i) {
		v[i] = max(v[i], v[i - 1]);
		for (int j = 1; 1ll * i * j <= c; ++j) {
			v[i * j] = max(v[i * j], 1ll * v[i] * j);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		long long x, y;
		cin >> x >> y;
		auto p = upper_bound(v, v + c + 1, 1ll * x * y) - v;
		if (p == c + 1) cout << "-1 ";
		else cout << p << ' ';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}