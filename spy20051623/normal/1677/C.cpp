#include <bits/stdc++.h>

using namespace std;

int a[100005], b[100005], c[100005], vis[100005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		c[a[i]] = b[i];
	}
	fill(vis, vis + n + 5, 0);
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		int x = i, cnt = 0;
		do {
			++cnt;
			x = c[x];
			vis[x] = 1;
		} while (x != i);
		v.push_back(cnt / 2 * 2);
	}
	long long ans = 0, cur = n;
	for (int i: v) {
		if (!i) continue;
		for (int j = 1; j <= i - 1; ++j) {
			ans += cur - j;
		}
		ans += cur - i / 2;
		cur -= i;
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