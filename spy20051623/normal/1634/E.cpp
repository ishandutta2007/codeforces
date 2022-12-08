#include <bits/stdc++.h>

using namespace std;

struct edge {
	int to, x, y;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	cin >> m;
	vector<vector<int>> v(m), u(m);
	map<int, int> mp;
	for (int i = 0; i < m; ++i) {
		int n;
		cin >> n;
		v[i] = vector<int>(n);
		u[i] = vector<int>(n);
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			++mp[v[i][j]];
		}
	}
	int cnt = 0;
	for (auto &i: mp) {
		if (i.second & 1) {
			cout << "NO\n";
			return 0;
		}
		i.second = cnt++;
	}
	cout << "YES\n";
	for (auto &i: v) for (int &j: i) j = mp[j];
	vector<queue<edge>> a(m), b(cnt);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			a[i].push({v[i][j], i, j});
			b[v[i][j]].push({i, i, j});
		}
	}
	for (int i = 0; i < m; ++i) {
		while (!a[i].empty()) {
			edge p = a[i].front();
			if (u[p.x][p.y]) {
				a[i].pop();
				continue;
			}
			int st = p.x, flag = 1, cur = p.x;
			do {
				flag == 1 ? a[cur].pop() : b[cur].pop();
				u[p.x][p.y] = flag;
				flag = -flag;
				cur = p.to;
				if (flag == 1) {
					while (!a[cur].empty() && u[a[cur].front().x][a[cur].front().y]) a[cur].pop();
					if (!a[cur].empty()) p = a[cur].front();
				} else {
					while (!b[cur].empty() && u[b[cur].front().x][b[cur].front().y]) b[cur].pop();
					if (!b[cur].empty()) p = b[cur].front();
				}
			} while (flag == -1 || cur != st);
		}
	}
	for (auto &i: u) {
		for (int j: i) cout << (j == 1 ? "L" : "R");
		cout << "\n";
	}
	return 0;
}