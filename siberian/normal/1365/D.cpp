#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char> (m, ' '));
	for (auto &i : a) {
		for (auto &j : i) {
			cin >> j;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 'B') continue;
			for (int it = 0; it < 4; it++) {
				int nx = i + dx[it], ny = j + dy[it];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (a[nx][ny] == 'G') {
					cout << "No\n";
					return;
				}
				if (a[nx][ny] == '.') {
					a[nx][ny] = '#';
				}
			}
		}
	}
	queue<pair<int, int>> q;
	vector<vector<bool>> used(n, vector<bool> (m, false));
	if (a[n - 1][m - 1] != '#') {
		q.push({n - 1, m - 1});
		used[n - 1][m - 1] = true;
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int it = 0; it < 4; it++) {
			int nx = x + dx[it], ny = y + dy[it];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (a[nx][ny] == '#') continue;
			if (used[nx][ny]) continue;
			used[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (used[i][j] && a[i][j] == 'B') {
				cout << "No\n";
				return;
			}
			if (!used[i][j] && a[i][j] == 'G') {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}