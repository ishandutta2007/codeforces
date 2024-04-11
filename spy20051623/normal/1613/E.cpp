#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
string s[1000005];
const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int n, m;

bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	if (s[x][y] != '.') return false;
	int cnt = 0;
	for (auto i: dir) {
		int nx = x + i[0], ny = y + i[1];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && s[nx][ny] == '.') ++cnt;
	}
	if (cnt < 2) return true;
	else return false;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int xx, yy;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'L') xx = i, yy = j;
		}
	}
	queue<pii> q;
	q.emplace(xx, yy);
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		for (auto i: dir) {
			int nx = x + i[0], ny = y + i[1];
			if (check(nx, ny)) {
				s[nx][ny] = '+';
				q.emplace(nx, ny);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << s[i] << '\n';
	}
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