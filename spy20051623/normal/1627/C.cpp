#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int x[N], y[N], c[N], a[N];
vector<int> e[N];

void solve() {
	int n;
	cin >> n;
	fill(c, c + n + 5, 0);
	for (int i = 1; i <= n; ++i) e[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		cin >> x[i] >> y[i];
		++c[x[i]];
		++c[y[i]];
		e[x[i]].push_back(i);
		e[y[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (c[i] > 2) {
			cout << "-1\n";
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (c[i] == 1) {
			int p = i, q = -1, d = 2;
			while (p == i || c[p] == 2) {
				if (e[p][0] != q) q = e[p][0];
				else q = e[p][1];
				if (x[q] == p) p = y[q];
				else p = x[q];
				a[q] = d;
				if (d == 2) d = 3;
				else d = 2;
			}
			break;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
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