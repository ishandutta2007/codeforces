#include <map>
#include <iostream>
using namespace std;
int n, m, p; long long x, a[24][24];
map<long long, int> p1[24], p2[24];
void dfs1(int px, int py, long long cur) {
	if (px + py == p) {
		++p1[px][cur];
		return;
	}
	if (px != n - 1) dfs1(px + 1, py, cur ^ a[px + 1][py]);
	if (py != m - 1) dfs1(px, py + 1, cur ^ a[px][py + 1]);
}
void dfs2(int px, int py, long long cur) {
	if (px + py == p) {
		++p2[px][cur];
		return;
	}
	if (px != 0) dfs2(px - 1, py, cur ^ a[px][py]);
	if (py != 0) dfs2(px, py - 1, cur ^ a[px][py]);
}
int main() {
	cin >> n >> m >> x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	p = (n + m - 2) / 2;
	dfs1(0, 0, a[0][0]);
	dfs2(n - 1, m - 1, 0);
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		for (pair<long long, int> j : p1[i]) {
			ret += 1LL * j.second * p2[i][j.first ^ x];
		}
	}
	cout << ret << '\n';
	return 0;
}