#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m, greater<int>());
	long long ans = 0;
	for (int i = 0; i < m; ++i) ans += a[n - m + i];
	int p = 0, q = n - 1;
	for (int i = 0; i < m; ++i) {
		if (b[i] == 1) ans += a[q--];
		else ans += a[p], p += b[i] - 1;
	}
	cout << ans << '\n';
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