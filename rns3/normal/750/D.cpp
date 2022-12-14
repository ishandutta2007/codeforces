#include <bits/stdc++.h>
using namespace std;

const int D = 200;
const int E = D << 1;
const int K = 8;

int n, t;

bool cur[D<<1][D<<1][8], vis[D<<1][D<<1];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct FIRE {
	int x, y, dir;
	FIRE (int x = 0, int y = 0, int dir = 0) : x(x), y(y), dir(dir) {}
	void go(int t) {
		for (int i = 0; i < t; i ++) {
			x += dx[dir];
			y += dy[dir];
			vis[x][y] = 1;
		}
	}
} fire[D*D*K];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	memset(cur, 0, sizeof cur);
	memset(vis, 0, sizeof vis);
	cur[D][D][0] = 1;
	vis[D][D] = 1;
	for (int h = 1, t; h <= n; h ++) {
		scanf("%d", &t);
		if (h == 1) t --;
		int cnt = 0;
		for (int i = 0; i < E; i ++) for (int j = 0; j < E; j ++) for (int k = 0; k < K; k ++) if (cur[i][j][k]) {
			fire[++cnt] = FIRE(i, j, k);
			fire[cnt].go(t);
		}
		memset(cur, 0, sizeof cur);
		for (int i = 1, x, y, dir; i <= cnt; i ++) {
			x = fire[i].x;
			y = fire[i].y;
			dir = fire[i].dir;
			cur[x][y][(dir+1)%K] = 1;
			cur[x][y][(dir+7)%K] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < E; i ++) for (int j = 0; j < E; j ++) if (vis[i][j]) ans ++;
	printf("%d\n", ans);

	return 0;
}