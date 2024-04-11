#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000];

void solve() {
	int n, k;
	cin >> n >> k;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) q.emplace(a[i], b[i]);
	while (!q.empty() && q.top().first <= k) {
		k += q.top().second;
		q.pop();
	}
	cout << k << '\n';
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