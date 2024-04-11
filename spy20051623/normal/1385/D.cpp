#include <bits/stdc++.h>

using namespace std;

string s;

int dfs(int l, int r, int x) {
	if (l == r) return s[l] != 'a' + x;
	int c1 = 0, c2 = 0;
	int m = (l + r) >> 1;
	for (int i = l; i <= m; ++i) c1 += s[i] != 'a' + x;
	for (int i = m + 1; i <= r; ++i) c2 += s[i] != 'a' + x;
	return min(c1 + dfs(m + 1, r, x + 1), c2 + dfs(l, m, x + 1));
}

void solve() {
	int n;
	cin >> n;
	cin >> s;
	cout << dfs(0, n - 1, 0) << '\n';
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