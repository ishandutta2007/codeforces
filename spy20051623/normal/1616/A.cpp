#include <bits/stdc++.h>

using namespace std;

int a[105];

void solve() {
	memset(a, 0, sizeof a);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		++a[abs(p)];
	}
	int cnt = 0;
	if (a[0]) ++cnt;
	for (int i = 1; i <= 100; ++i) {
		cnt += min(a[i], 2);
	}
	cout << cnt << '\n';
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