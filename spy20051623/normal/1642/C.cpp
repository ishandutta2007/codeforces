#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	multiset<long long> s;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		s.insert(p);
	}
	int ans = 0;
	while (!s.empty()) {
		int p = *s.begin();
		s.erase(s.begin());
		auto it = s.find(1ll * x * p);
		if (it == s.end()) ++ans;
		else s.erase(it);
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