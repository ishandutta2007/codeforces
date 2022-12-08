#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n, k;
	cin >> n >> k;
	multiset<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		s.erase(s.find(a[i]));
		if (s.find(a[i] + k) != s.end()) {
			cout << "YES\n";
			return;
		}
		s.insert(a[i]);
	}
	cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}