#include<bits/stdc++.h>
using std::cin;
using std::cout;
using i16 = short;
const int N = 501;
int n, m, D;
struct edge {
	int to, nxt;
} way[N << 1];
int h[N], num;
inline void link(int x, int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
i16 dp[N][N][N];
int dis[N][N], g[N][N], size[N], c[N], cnt;
inline void down(int & x, int y) {
	if(x > y) {
		x = y;
	}
}
inline void dfs0(int x, int fa = 0) {
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa) {
		dfs0(way[i].to, x);
	}
	for(int i = 1;i <= n;++i) {
		if(dis[x][i] <= D) {
			size[x] = 1;
			dp[x][i][1] = !c[i];
			for(int j = h[x];j;j = way[j].nxt) {
				int to = way[j].to;
				if(to != fa) {
					for(int k = std::min(size[x] + size[to], cnt);k >= 0;--k) {
						int t = (1 << 15) - 1;
						for(int l = std::max(k - size[x], 0);l <= k && l <= size[to];++l) {
							down(t, dp[x][i][k - l] + g[to][l]);
						}
						for(int l = std::max(k - size[x] + 1, 1);l <= k && l <= size[to];++l) {
							down(t, dp[x][i][k - l + 1] + dp[to][i][l] - !c[i]);
						}
						dp[x][i][k] = t;
					}
					size[x] += size[to];
				}
			}
		}
	}
	for(int i = 0;i <= cnt && i <= size[x];++i) {
		g[x][i] = 1e9;
		for(int j = 1;j <= n;++j) {
			g[x][i] = std::min<int>(g[x][i], dp[x][j][i]);
		}
	}
	
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> D;
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			dis[i][j] = 1.05e9;
		}
	}
	for(int i = 1;i <= n;++i) {
		cin >> c[i];
		cnt += c[i];
		dis[i][i] = 0;
	}
	for(int i = 1, x, y, w;i < n;++i) {
		cin >> x >> y >> w;
		dis[x][y] = w;
		dis[y][x] = w;
		link(x, y);
	}
	for(int k = 1;k <= n;++k) {
		for(int i = 1;i <= n;++i) {
			for(int j = 1;j <= n;++j) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			for(int k = 0;k <= cnt;++k) {
				dp[i][j][k] = (1 << 15) - 1;
			}
		}
	}
	dfs0(1);
	cout << (g[1][cnt] >= (1 << 15) - 1 ? -1 : g[1][cnt]) << '\n';
}