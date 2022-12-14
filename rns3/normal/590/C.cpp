#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;
#define M 1111

int n, m;
char s[M][M];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool ok(int x, int y) {return x && y && (x<=n) && (y<=m);}
const int inf = 10010010;

int dis[4][M][M];
int q[M*M*2], st, en;

int flag[M][M];


int main() {
    //freopen("C.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)scanf("%s", s[i] + 1);

    for (int c = 1; c <= 3; c++) {
        st = en = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)dis[c][i][j] = inf;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (s[i][j] == '0' + c) {
            q[++en] = i;
            q[++en] = j;
            flag[i][j] = c;
            dis[c][i][j] = 0;
        }
        bool chk[5];
        for (int i = 0; i < 5; i++) chk[i] = 0;
        for (int x, y; st <en; ) {
            x = q[++st];
            y = q[++st];
            for (int r = 0; r < 4; r++) {
                int xx = x + dx[r];
                int yy = y +dy[r];
                if (!ok(xx, yy) || flag[xx][yy] == c || s[xx][yy] == '#') continue;
                flag[xx][yy] = c;
                if (s[xx][yy] =='.') {
                    q[++en] = xx;
                    q[++en] = yy;
                    dis[c][xx][yy] = dis[c][x][y] + (s[xx][yy] == '.');
                    continue;
                }
                int d = s[xx][yy] - '0';
                for (int ii = 1; ii <= n; ii++) for (int jj = 1; jj <= m; jj++)if (s[ii][jj] == s[xx][yy]) {
                    flag[ii][jj] = c;
                    dis[c][ii][jj] = dis[c][x][y];
                    q[++en] = ii;
                    q[++en] = jj;
                }
            }
        }
    }

    int answer = inf;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (s[i][j] != '#') {
        int x = i, y = j;
        int d = dis[1][x][y] + dis[2][x][y] + dis[3][i][j];
        if (s[x][y] == '.') d = d - 2;
        if (answer>d) answer= d;
    }
    if (answer > inf / 2) puts("-1");
    else printf("%d\n", answer);
    return 0;
}