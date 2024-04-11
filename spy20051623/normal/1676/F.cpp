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
	int l = -1, r = -2, cur = -1, lst = -2;
	for (auto i: mp) {
		if (i.second < k) cur = -1, lst = -2;
		else if (i.first == lst + 1) lst = i.first;
		else cur = lst = i.first;
		if (lst - cur > r - l) l = cur, r = lst;
	}
	if (l == -1) cout << "-1\n";
	else cout << l << ' ' << r << '\n';
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