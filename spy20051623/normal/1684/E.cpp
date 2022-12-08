#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++mp[a[i]];
	}
	int cnt = 0, mex = 0;
	for (int i = 0; i <= n; ++i) {
		mex = i;
		if (i == n) break;
		if (!mp.count(i)) {
			if (cnt < k) ++cnt;
			else break;
		}
	}
	priority_queue<int, vector<int>, greater<>> q;
	for (auto i = mp.lower_bound(mex); i != mp.end(); ++i) {
		q.push(i->second);
	}
	int ans = mp.size() - mex + cnt;
	while (!q.empty() && k >= q.top()) {
		--ans;
		k -= q.top();
		q.pop();
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