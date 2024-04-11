#include <bits/stdc++.h>

using namespace std;

int a[1000005], mn[1000005];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int g = 0;
	for (int i = 0; i < m; ++i) {
		int p;
		cin >> p;
		g = __gcd(g, p);
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i) sum += abs(a[i]);
	if (g == 1) {
		cout << sum << '\n';
		return;
	}
	for (int i = 0; i < g; ++i) {
		mn[i] = 2e9;
		int c = 0;
		for (int j = i; j < n; j += g) {
			if (a[j] < 0) ++c;
			mn[i] = min(mn[i], abs(a[j]));
		}
		if (c & 1) mn[i] *= -1;
	}
	long long s1 = 0, s2 = 0;
	for (int i = 0; i < g; ++i) {
		if (mn[i] < 0) s1 -= mn[i];
		else s2 += mn[i];
	}
	cout << sum - 2 * min(s1, s2) << '\n';
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