#include <bits/stdc++.h>

using namespace std;

int a[5005], f[5005][5005], g[5005][5005];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		g[n + 1][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j < a[i]) f[i][j] = f[i - 1][j];
			else f[i][j] = f[i - 1][j] + 1;
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= n; ++j) {
			if (j < a[i]) g[i][j] = g[i + 1][j];
			else g[i][j] = g[i + 1][j] + 1;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans += f[i - 1][a[j] - 1] * g[j + 1][a[i] - 1];
		}
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