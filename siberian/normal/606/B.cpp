#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

int n, m;
const int MAXN = 510;
string s;
int used[MAXN][MAXN];

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	x--;
	y--;
	string s;
	cin >> s;
	int now = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			used[i][j] = -1;
		}
	}

	for (auto i : s) {
		int dx, dy;
		if (i == 'U') dx = -1, dy = 0;
		else if (i == 'D') dx = 1, dy = 0;
		else if (i == 'L') dx = 0, dy = -1;
		else dx = 0, dy = 1;
		int nx = x + dx, ny = y + dy;
		if (used[x][y] == -1)
		used[x][y] = now;
 		if (check(nx, ny)) {
 			x = nx;
 			y = ny;
		}
		now++;
	}

	vector<int> ans(s.size() + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (used[i][j] == -1) used[i][j] = s.size();
			ans[used[i][j]]++;
		}
	}

	for (auto i: ans)
		cout << i << " ";
	cout << endl;
	return 0;
}