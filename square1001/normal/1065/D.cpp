#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N;
	cin >> N;
	vector<vector<int> > A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<pair<int, int> > dp(3, make_pair(0, 0));
	for (int i = 1; i < N * N; ++i) {
		int sx = -1, sy = -1, gx = -1, gy = -1;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (A[j][k] == i) sx = j, sy = k;
				if (A[j][k] == i + 1) gx = j, gy = k;
			}
		}
		vector<pair<int, int> > ndp(3, make_pair(inf, inf));
		for (int j = 0; j < 3; ++j) {
			vector<vector<vector<pair<int, int> > > > d(N, vector<vector<pair<int, int> > >(N, vector<pair<int, int> >(3, make_pair(inf, inf))));
			queue<vector<int> > que;
			d[sx][sy][j] = make_pair(0, 0);
			que.push({ sx, sy, j });
			while (!que.empty()) {
				vector<int> u = que.front(); que.pop();
				for (int k = 0; k < 3; ++k) {
					pair<int, int> rel = d[u[0]][u[1]][u[2]]; ++rel.first; ++rel.second;
					if (k != u[2] && d[u[0]][u[1]][k] > rel) {
						d[u[0]][u[1]][k] = rel;
						que.push({ u[0], u[1], k });
					}
				}
				for (int nx = 0; nx < N; ++nx) {
					for (int ny = 0; ny < N; ++ny) {
						int dx = u[0] - nx, dy = u[1] - ny;
						if (u[2] == 0 && abs(dx) * abs(dy) != 2) continue;
						if (u[2] == 1 && abs(dx) != abs(dy)) continue;
						if (u[2] == 2 && abs(dx) * abs(dy) != 0) continue;
						pair<int, int> rel = d[u[0]][u[1]][u[2]]; ++rel.first;
						if (d[nx][ny][u[2]] > rel) {
							d[nx][ny][u[2]] = rel;
							que.push({ nx, ny, u[2] });
						}
					}
				}
			}
			for (int k = 0; k < 3; ++k) {
				ndp[k] = min(ndp[k], make_pair(dp[j].first + d[gx][gy][k].first, dp[j].second + d[gx][gy][k].second));
			}
		}
		dp = ndp;
	}
	pair<int, int> ans = min({ dp[0], dp[1], dp[2] });
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}