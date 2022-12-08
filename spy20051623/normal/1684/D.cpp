#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	long long tot = 0;
	priority_queue<int> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		tot += a[i];
		q.push(a[i] - (n - i - 1));
	}
	long long ans = tot;
	for (int i = 0; i < k; ++i) {
		tot -= q.top() + i;
		q.pop();
		ans = min(ans, tot);
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