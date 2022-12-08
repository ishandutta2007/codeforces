#include <bits/stdc++.h>

using namespace std;

int a[200005];
long long s[2][200005];

void solve() {
	int n;
	cin >> n;
	long long ans = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
		s[i & 1][i] = s[i & 1][i - 1] + a[i];
		s[i & 1 ^ 1][i] = s[i & 1 ^ 1][i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, s[i & 1][i] + s[i & 1 ^ 1][n] - s[i & 1 ^ 1][i]);
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
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}