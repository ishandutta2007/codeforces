#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int d[N];
int tot;

int lowbit(int x) { return x & -x; }

void upd(int x, int k) { for (; x <= tot; x += lowbit(x)) d[x] += k; }

int qry(int x) {
	int s = 0;
	for (; x; x -= lowbit(x)) s += d[x];
	return s;
}

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	tot = n * m;
	vector<string> mp(n);
	for (int i = 0; i < n; ++i) {
		cin >> mp[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == '*') {
				upd(j * n + i + 1, 1);
				++cnt;
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (mp[x][y] == '.') {
			mp[x][y] = '*';
			upd(y * n + x + 1, 1);
			++cnt;
		} else {
			mp[x][y] = '.';
			upd(y * n + x + 1, -1);
			--cnt;
		}
		cout << cnt - qry(cnt) << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}