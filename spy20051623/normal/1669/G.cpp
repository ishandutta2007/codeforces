#include <bits/stdc++.h>

using namespace std;

long long a[200005], s[200005];

void solve() {
	int n, m;
	cin >> n >> m;
	string mp[100];
	for (int i = 0; i < n; ++i) {
		cin >> mp[i];
	}
	for (int i = 0; i < m; ++i) {
		int p = n;
		for (int j = n - 1; j >= 0; --j) {
			if (mp[j][i] == 'o') p = j;
			else if (mp[j][i] == '*') swap(mp[j][i], mp[--p][i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << mp[i] << '\n';
	}
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