#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 51;
int color[MAXN][MAXN];
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
int n;
char table[MAXN][MAXN];

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n && table[x][y] == '0';
}

void dfs(int x, int y, int c) {
	color[x][y] = c;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check(nx, ny)) continue;
		if (color[nx][ny]) continue;
		dfs(nx, ny, c);
	}
}

pair<int, int> a, b;

void solve() {
	cin >> n;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	a.first--;
	a.second--;
	b.first--;
	b.second--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> table[i][j];
	int c = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!color[i][j] && table[i][j] == '0')
				dfs(i, j, c++);
		}
	}
	int ans = 1e9;
	for (int x1 = 0; x1 < n; x1++)
		for (int y1 = 0; y1 < n; y1++)
			for (int x2 = 0; x2 < n; x2++)
				for (int y2 = 0; y2 < n; y2++)
					if (color[x1][y1] == color[a.first][a.second] && color[x2][y2] == color[b.first][b.second])
						chkmin(ans, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}