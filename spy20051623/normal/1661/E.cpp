#include <bits/stdc++.h>

using namespace std;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
const int N = 5e5 + 5;
int a[5][N], b[5][N], L[N << 2], R[N << 2];
int cl[N], cr[N], bl[N], br[N];

void solve() {
	memset(L, 63, sizeof L);
	int n;
	cin >> n;
	for (int i = 1; i <= 3; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			a[i][j + 1] = s[j] - '0';
		}
	}
	int tot = 0;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!a[i][j] || b[i][j]) continue;
			++tot;
			b[i][j] = tot;
			queue<pair<int, int>> q;
			q.emplace(i, j);
			while (!q.empty()) {
				auto p = q.front();
				q.pop();
				for (auto k: d) {
					int x = p.first + k[0], y = p.second + k[1];
					if (a[x][y] && !b[x][y]) {
						b[x][y] = tot;
						q.emplace(x, y);
					}
				}
			}
		}
	}
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!a[i][j]) continue;
			L[b[i][j]] = min(L[b[i][j]], j);
			R[b[i][j]] = max(R[b[i][j]], j);
		}
	}
	for (int i = 1; i <= tot; ++i) {
		++cl[R[i]];
		++cr[L[i]];
	}
	int bg = -1;
	for (int i = 1; i <= n; ++i) {
		cl[i] += cl[i - 1];
		if (a[2][i]) bg = i;
		if (!a[1][i] || !a[3][i]) bg = -1;
		bl[i] = bg;
	}
	for (int i = n; i >= 1; --i) {
		cr[i] += cr[i + 1];
		if (a[2][i]) bg = i;
		if (!a[1][i] || !a[3][i]) bg = -1;
		br[i] = bg;
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = tot - cl[x - 1] - cr[y + 1];
		if (b[1][x] && b[1][x] == b[3][x] && (bl[x] == -1 || bl[x] < x) && (br[x] == -1 || br[x] > y)) ++ans;
		if (b[1][y] && b[1][y] == b[3][y] && (bl[y] == -1 || bl[y] < x) && (br[y] == -1 || br[y] > y)) ++ans;
		if (b[1][x] && b[1][x] == b[3][x] && (bl[x] == -1 || bl[x] < x) && (br[x] == -1 || br[x] > y) &&
			b[1][y] && b[1][y] == b[3][y] && (bl[y] == -1 || bl[y] < x) && (br[y] == -1 || br[y] > y) &&
			b[1][x] == b[1][y] && (bl[x] != -1 && bl[x] == bl[y] || br[y] != -1 && br[x] == br[y]))
			--ans;
		cout << ans << '\n';
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