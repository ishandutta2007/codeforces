#include <bits/stdc++.h>

using namespace std;

vector<int> g[1005];
int vis[1005];

bool qry(int p, int d, int &a, int &b) {
	vector<int> v;
	function<void(int, int, int)> dfs = [&](int p, int k, int f) {
		if (!k) v.push_back(p);
		for (int i: g[p]) {
			if (!vis[i] && i != f) dfs(i, k - 1, p);
		}
	};
	dfs(p, d, 0);
	if (v.empty()) return false;
	cout << "? " << v.size();
	for (int i: v) cout << ' ' << i;
	cout << endl;
	cin >> a >> b;
	return true;
}

void solve() {
	for (int i = 0; i < 1005; ++i) {
		g[i].clear();
		vis[i] = 0;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout << "? " << n << ' ';
	for (int i = 1; i <= n; ++i) {
		cout << ' ' << i;
	}
	cout << endl;
	int pos, dis;
	cin >> pos >> dis;
	int npos, ndis;
	for (int i = 9; i >= 0; --i) {
		if (qry(pos, 1 << i, npos, ndis) && ndis <= dis) {
			vector<int> v;
			function<bool(int, int, int)> dfs = [&](int p, int f, int k) {
				if (p == k) return true;
				for (int i: g[p]) {
					if (i != f) {
						v.push_back(i);
						if (dfs(i, p, k)) return true;
						v.pop_back();
					}
				}
				return false;
			};
			dfs(pos, 0, npos);
			for (int j: v) vis[j] = 1;
			pos = npos;
			dis = ndis;
		}
	}
	memset(vis, 0, sizeof vis);
	qry(pos, dis, npos, ndis);
	cout << "! " << pos << ' ' << npos << endl;
	string s;
	cin >> s;
	if (s == "Incorrect") exit(-1);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}