#include <bits/stdc++.h>

using namespace std;

priority_queue<int> Q;

bool check(int d) {
	priority_queue<int> q = Q;
	vector<int> v;
	++d;
	while (true) {
		v.clear();
		for (int i = 0; i < d; ++i) {
			if (q.empty()) return v.empty();
			int p = q.top();
			q.pop();
			if (p > 1) v.push_back(p - 1);
		}
		for (int i: v) q.push(i);
	}
}

void solve() {
	while (!Q.empty()) Q.pop();
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++mp[x];
	}
	for (auto i: mp) {
		Q.push(i.second);
	}
	int l = 0, r = Q.size() - 1, ans;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (check(m)) ans = m, l = m + 1;
		else r = m - 1;
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