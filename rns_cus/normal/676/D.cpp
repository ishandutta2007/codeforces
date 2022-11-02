#include <bits/stdc++.h>
using namespace std;

#define M 2001

struct dat{
	int x, y, z, w;
	dat(int x = 0, int y = 0, int z = 0, int w = 0):x(x), y(y), z(z), w(w){}
};

bool operator < (dat A, dat B) {
	if(A.w != B.w) return A.w > B.w;
    return 0;
}

int dis[M][M][4], di[M][M][4];
char s[M][M];

bool can_go(int x, int y, int z, int d) {
	int zz = (d - z + 4) % 4;
	if(di[x][y][zz]) return 1;
	return 0;
}

priority_queue<dat, vector<dat> > Q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;

bool range(int x, int y) {
	if(1 <= x && x <= n && 1 <= y && y <= m) return 1;
	return 0;
}

int rev(int x) {
	if(x % 2) return 4 - x;
	return 2 - x;
}

int main() {
	//freopen("D.in", "r", stdin);

	scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(s[i][j] == '+') di[i][j][0] = di[i][j][1] = di[i][j][2] = di[i][j][3] = 1;
            else if(s[i][j] == '-') di[i][j][0] = di[i][j][2] = 1;
            else if(s[i][j] == '|') di[i][j][1] = di[i][j][3] = 1;
            else if(s[i][j] == '^') di[i][j][3] = 1;
            else if(s[i][j] == '>') di[i][j][0] = 1;
            else if(s[i][j] == '<') di[i][j][2] = 1;
            else if(s[i][j] == 'v') di[i][j][1] = 1;
            else if(s[i][j] == 'L') di[i][j][0] = di[i][j][1] = di[i][j][3] = 1;
            else if(s[i][j] == 'R') di[i][j][1] = di[i][j][2] = di[i][j][3] = 1;
            else if(s[i][j] == 'U') di[i][j][0] = di[i][j][1] = di[i][j][2] = 1;
            else if(s[i][j] == 'D') di[i][j][0] = di[i][j][2] = di[i][j][3] = 1;
        }
    }
    int X, Y, XX, YY;
    scanf("%d %d %d %d", &X, &Y, &XX, &YY);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) for(int d = 0; d < 4; d ++) dis[i][j][d] = 1e9;
	Q.push(dat(X, Y, 0, 0));
    dis[X][Y][0] = 0;
	while(!Q.empty()) {
        dat A = Q.top(); Q.pop();
		int x = A.x, y = A.y, z = A.z, w = A.w;
		if(dis[x][y][z] != w) continue;
        dis[x][y][z] = w;
        for(int d = 1; d < 2; d ++) {
            int zz = (z + d) % 4;
            if(dis[x][y][zz] <= w + 1) continue;
            dis[x][y][zz] = w + 1;
            Q.push(dat(x, y, zz, w + 1));
        }
        for(int d = 0; d < 4; d ++) {
			int xx = x + dx[d], yy = y + dy[d];
            if(range(xx, yy) && can_go(x, y, z, d) && can_go(xx, yy, z, rev(d)) && dis[xx][yy][z] > w + 1) {
				dis[xx][yy][z] = w + 1;
				Q.push(dat(xx, yy, z, w + 1));
            }
        }
	}
	int ans = 1e9;
	for(int d = 0; d < 4; d ++) ans = min(ans, dis[XX][YY][d]);
	if(ans == 1e9) return puts("-1");
	printf("%d\n", ans);
}