#include <bits/stdc++.h>

using namespace std;

string s[105];
int fa[100000];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n * m; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'D' && i < n - 1) fa[i * m + j] = find((i + 1) * m + j);
			if (s[i][j] == 'R' && j < m - 1) fa[i * m + j] = find(i * m + j + 1);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n * m; ++i) {
		if (fa[i] == i) ++cnt;
	}
	cout << cnt - 1 << '\n';
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