#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::priority_queue<int> q1, q2;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		q1.push(x);
	}
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		q2.push(x);
	}
	int ans = 0;
	while (!q1.empty()) {
		if (q1.top() == q2.top()) {
			q1.pop();
			q2.pop();
			continue;
		}
		if (q1.top() > q2.top()) {
			int p = q1.top();
			q1.pop();
			q1.push(log10(p) + 1);
			++ans;
		} else {
			int p = q2.top();
			q2.pop();
			q2.push(log10(p) + 1);
			++ans;
		}
	}
	std::cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}