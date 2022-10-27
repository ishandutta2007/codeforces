#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
typedef long long LL;
int n, m, t;
char s[N][N];
bool flag[N][N];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool in(int x, int y) {
	return x>=1 && x<=n && y>=1 && y<=m;
}
int dis[N][N];

int main() {
	memset(dis, -1, sizeof(dis));
	memset(flag, 0, sizeof(flag));

	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			for (int k = 0; k < 4; k ++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (in(nx, ny) && s[i][j] == s[nx][ny]) {
					flag[i][j] = 1;
				}
			}
		}
	}
	queue< pair<int,int> > q;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (flag[i][j]) {
				q.push(make_pair(i, j));
				dis[i][j] = 0;
			}
		}
	}
	while (q.size()) {
		pair<int, int> now = q.front(); q.pop();
		int x = now.first, y = now.second;
		for (int i = 0; i < 4; i ++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (in(nx, ny) && s[x][y] != s[nx][ny] && dis[nx][ny] == -1) {
				dis[nx][ny] = dis[x][y] + 1; q.push(make_pair(nx, ny));
			}
		}
	}
	while (t --) {
		int i, j; LL p;
		scanf("%d%d%lld", &i, &j, &p);
		if (dis[i][j] == -1) {
			printf("%c\n", s[i][j]); continue;
		}
		if (p <= dis[i][j]) {
			printf("%c\n", s[i][j]); continue;
		}
		//printf("# %d\n", dis[i][j]);
		int now = s[i][j] - '0';
		int ans = ((p%2) + now) % 2;
		if (dis[i][j] % 2 == 1) ans ^= 1;
		printf("%d\n", ans);
	}
}