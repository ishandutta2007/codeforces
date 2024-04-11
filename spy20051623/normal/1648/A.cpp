#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	map<int, long long> s, c;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans += c[a[i][j]] * i - s[a[i][j]];
			s[a[i][j]] += i;
			++c[a[i][j]];
		}
	}
	s.clear(), c.clear();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			ans += c[a[j][i]] * i - s[a[j][i]];
			s[a[j][i]] += i;
			++c[a[j][i]];
		}
	}
	cout << ans;
	return 0;
}