#include <bits/stdc++.h>

using namespace std;

long long a[200005], b[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	b[n + 1] = b[n + 2] = 0;
	long long l = 1, r = 1e10, ans;
	while (l <= r) {
		long long m = (l + r) >> 1;
		bool ok = true;
		for (int i = n; i >= 1; --i) {
			if (a[i] + b[i + 1] + 2 * b[i + 2] < m) {
				ok = false;
				break;
			}
			if (i >= 3)
				b[i] = min(a[i] / 3, (a[i] + b[i + 1] + 2 * b[i + 2] - m) / 3);
		}
		if (ok) ans = m, l = m + 1;
		else r = m - 1;
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