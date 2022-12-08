#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9;
int a[200005];
int x[200005];
int y[200005];
int n;

int dfs1(int);

int dfs2(int);

int dfs1(int p) {
	if (x[p] != -1) return x[p];
	if (p >= n) return inf;
	if (p == n - 1) return x[p] = a[p];
	return x[p] = min(a[p] + dfs2(p + 1), a[p] + a[p + 1] + dfs2(p + 2));
}

int dfs2(int p) {
	if (y[p] != -1) return y[p];
	if (p >= n) return inf;
	if (p >= n - 2) return y[p] = 0;
	return y[p] = min(dfs1(p + 1), dfs1(p + 2));
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(x, -1, (n << 2) + 5);
	memset(y, -1, (n << 2) + 5);
	cout << dfs1(0) << '\n';
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