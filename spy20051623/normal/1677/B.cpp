#include <bits/stdc++.h>

using namespace std;

int a[1000005], s[1000005], vis[1000005], dp[1000005];

void solve() {
	int n, m;
	cin >> n >> m;
	int x = n * m;
	string str;
	cin >> str;
	for (int i = 1; i <= x; ++i) {
		a[i] = str[i - 1] - '0';
		s[i] = s[i - 1] + a[i];
	}
	fill(vis, vis + x + 5, 0);
	int cnt = 0;
	for (int i = 1; i <= x; ++i) {
		if (a[i] && !vis[(i - 1) % m]) {
			vis[(i - 1) % m] = 1;
			++cnt;
		}
		if (i <= m) {
			dp[i] = s[i] > 0;
		} else {
			dp[i] = dp[i - m] + (s[i] - s[i - m] > 0);
		}
		cout << cnt + dp[i] << ' ';
	}
	cout << "\n";
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