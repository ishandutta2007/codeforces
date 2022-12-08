#include <bits/stdc++.h>

using namespace std;

int a[200005];
multiset<long long> s;

bool dfs(long long x) {
	auto it = s.find(x);
	if (it != s.end()) {
		s.erase(it);
		return true;
	}
	if (x <= 1) return false;
	long long p = (x + 1) / 2, q = x / 2;
	return dfs(p) && dfs(q);
}

void solve() {
	s.clear();
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		s.insert(a[i]);
	}
	if (dfs(sum)) cout << "YES\n";
	else cout << "NO\n";
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