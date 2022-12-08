#include <bits/stdc++.h>

using namespace std;

int a[105], b[105];
bool v[105][10005];

void solve() {
	int n;
	cin >> n;
	int sum = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i], ans += a[i] * a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i], sum += b[i], ans += b[i] * b[i];
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= n * 100; ++j) v[i][j] = false;
	v[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n * 100; ++j) {
			if (v[i - 1][j]) {
				v[i][j + a[i]] = true;
				v[i][j + b[i]] = true;
			}
		}
	}
	ans *= n - 2;
	int tmp = 1e9;
	for (int i = 0; i <= n * 100; ++i) {
		if (v[n][i]) tmp = min(tmp, i * i + (sum - i) * (sum - i));
	}
	ans += tmp;
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