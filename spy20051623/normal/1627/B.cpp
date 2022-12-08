#include <bits/stdc++.h>

using namespace std;

const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	int x = (n + 1) % 2 + 1, y = (m + 1) % 2 + 1, d = n / 2 + m / 2;
	queue<pair<int, int>> q;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cout << d << ' ';
			v[(n + 1) / 2 + i][(m + 1) / 2 + j] = d;
			q.emplace((n + 1) / 2 + i, (m + 1) / 2 + j);
		}
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (auto i: dir) {
			int xx = p.first + i[0], yy = p.second + i[1];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !v[xx][yy]) {
				v[xx][yy] = v[p.first][p.second] + 1;
				cout << v[xx][yy] << ' ';
				q.emplace(xx, yy);
			}
		}
	}
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}