#include <bits/stdc++.h>

using namespace std;
const int N = 4e5 + 5;
int f[N], fa[N << 1], dpt[N], l[N], r[N], dir[N];
char ans[N], mk[N];
vector<int> g[N], path[N], grp[N << 1];
vector<pair<int, int>> pos[N];
string s[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int p) {
	for (int i: g[p]) {
		if (i == f[p]) continue;
		f[i] = p;
		dpt[i] = dpt[p] + 1;
		dfs(i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= q + q; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dpt[1] = 1;
	dfs(1);
	for (int i = 1; i <= q; ++i) {
		cin >> l[i] >> r[i] >> s[i];
		int x = l[i], y = r[i];
		vector<int> u, v;
		while (x != y) {
			if (dpt[x] > dpt[y]) u.push_back(x), x = f[x];
			else v.push_back(y), y = f[y];
		}
		reverse(v.begin(), v.end());
		u.push_back(x);
		for (int j: v) u.push_back(j);
		path[i] = u;
		for (int j = 0; j < u.size(); ++j) {
			if (s[i][j] != s[i][s[i].length() - 1 - j]) pos[u[j]].emplace_back(i, j);
			else if (!mk[u[j]]) mk[u[j]] = s[i][j];
			else if (mk[u[j]] != s[i][j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		bool flag = false;
		vector<int> v[26];
		for (auto j: pos[i]) {
			v[s[j.first][j.second] - 'a'].push_back(j.first);
			v[s[j.first][s[j.first].length() - 1 - j.second] - 'a'].push_back(j.first + q);
		}
		for (int j = 0; j < 26; ++j) {
			if (j + 'a' == mk[i] || !mk[i] && v[j].size() == pos[i].size()) {
				for (int k = 1; k < v[j].size(); ++k) {
					fa[find(v[j][k])] = find(v[j][0]);
				}
				flag = true;
			} else {
				for (int k: v[j]) {
					fa[find(k)] = find(0);
				}
			}
		}
		if (!flag) {
			cout << "NO\n";
			return 0;
		}
	}
	memset(ans, 'a', sizeof ans);
	for (int i = 1; i <= q; ++i) {
		if (find(i) == find(i + q)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= q + q; ++i) {
		grp[find(i)].push_back(i);
	}
	memset(dir, -1, sizeof dir);
	for (int i = 1; i <= q; ++i) {
		if (dir[i] == -1) {
			if (find(i) != find(0)) {
				for (int j: grp[find(i)]) {
					if (j <= q) dir[j] = 0;
					else dir[j - q] = 1;
				}
			} else {
				for (int j: grp[find(i + q)]) {
					if (j <= q) dir[j] = 0;
					else dir[j - q] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		if (dir[i] == 0) {
			for (int j = 0; j < s[i].length(); ++j) {
				ans[path[i][j]] = s[i][j];
			}
		} else {
			for (int j = 0; j < s[i].length(); ++j) {
				ans[path[i][j]] = s[i][s[i].length() - 1 - j];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i];
	}
	return 0;
}