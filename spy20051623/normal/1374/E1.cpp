#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> a, b, c;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (y && z) a.push(x);
		else if (y) b.push(x);
		else if (z) c.push(x);
	}
	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		long long x = 1e18, y = 1e18;
		if (!a.empty()) x = a.top();
		if (!b.empty() && !c.empty()) y = b.top() + c.top();
		if (x > 1e10 && y > 1e10) {
			cout << "-1\n";
			return;
		}
		ans += min(x, y);
		if (x < y) a.pop();
		else b.pop(), c.pop();
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