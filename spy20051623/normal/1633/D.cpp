#include <bits/stdc++.h>

using namespace std;

int p[1005], a[1005], b[1005], dp[12005];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) a[i] = p[a[i]];
	int sum = 0;
	for (int i = 0; i < n; ++i) sum += a[i];
	if (k >= sum) {
		sum = 0;
		for (int i = 0; i < n; ++i) sum += b[i];
		cout << sum << '\n';
		return;
	}
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; ++i) {
		for (int j = k; j >= a[i]; --j) {
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}
	cout << dp[k] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(p, 63, sizeof p);
	p[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= x; ++i) {
			if (x + x / i <= 1000 && p[x + x / i] > p[x] + 1) {
				p[x + x / i] = p[x] + 1;
				q.push(x + x / i);
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}