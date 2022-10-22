#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 1005;
int n, m, a[N][N];
bool used[N][N];
vector<tuple<int, int, int> > ans;
queue<tuple<int, int, int> > que;
void ps(int i, int j) {
	if (i >= 1 && i < n && j >= 1 && j < m) {
		static int v[4];
		int len = 0;
		rep(x, 0, 1) rep(y, 0, 1) if (!used[i + x][j + y]) v[len++] = a[i + x][j + y];
		if (len) {
			rep(i, 1, len - 1) if (v[i] != v[i - 1]) return;
			que.emplace(i, j, v[0]);
		}
	}
}
const int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 }, dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
void put(int i, int j) {
	if (i >= 1 && i < n && j >= 1 && j < m) {
		static int v[4];
		int len = 0;
		rep(x, 0, 1) rep(y, 0, 1) if (!used[i + x][j + y])
			v[len++] = a[i + x][j + y];
		if (len) {
			rep(i, 1, len - 1) if (v[i] != v[i - 1]) return;
			rep(x, 0, 1) rep(y, 0, 1) if (!used[i + x][j + y]) used[i + x][j + y] = 1;
			ans.emplace_back(i, j, v[0]);
			rep(k, 0, 7) {
				int x_ = i + dx[k], y_ = j + dy[k];
				ps(x_, y_);
			}
		}
	}
}
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
	rep(i, 1, n - 1) rep(j, 1, m - 1) {
		ps(i, j);
	}
	while (!que.empty()) {
		int x, y, z;
		tie(x, y, z) = que.front();
		que.pop();
		put(x, y);
	}
	bool gg = 0;
	rep(i, 1, n) rep(j, 1, m) if (!used[i][j]) gg = 1;
	if (gg) {
		puts("-1"), exit(0);
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (auto& x: ans) {
		printf("%d %d %d\n", get<0>(x), get<1>(x), get<2>(x));
	}
}