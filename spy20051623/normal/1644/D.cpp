#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

const int N = 2e5 + 5;
int a[N], b[N], x[N], y[N];

void solve() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < q; ++i) {
		cin >> x[i] >> y[i];
	}
	long long ans = 1;
	for (int i = q - 1; i >= 0; --i) {
		if (!a[x[i]] || !b[y[i]]) ans = ans * k % mod;
		if (!a[x[i]]) a[x[i]] = 1, --n;
		if (!b[y[i]]) b[y[i]] = 1, --m;
		if (!n || !m) break;
	}
	cout << ans << '\n';
	for (int i = 0; i < q; ++i) {
		a[x[i]] = b[y[i]] = 0;
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