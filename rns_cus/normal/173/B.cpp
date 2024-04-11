#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define M 1010

int dis[M][M][5], n, m;

pair <int, int> nxt[M][M][5];

char s[M][M];

struct dat {
  int x, y, d;
  dat (int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) {}
  bool operator < (const dat &a) const {
    if (dis[x][y][d] != dis[a.x][a.y][a.d]) {
      return dis[x][y][d] > dis[a.x][a.y][a.d];
    }
    return make_pair(x, y) < make_pair(a.x, a.y);
  }
} ;

priority_queue <dat> q;

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    for (int k = 0; k < 4; k++) dis[i][j][k] = INF;
  for (int i = 1; i <= m; i++) if (s[1][i] == '#') {
    q.push(dat(1, i, 0)); dis[1][i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int x = i, y = 0;
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') nxt[i][j][2] = make_pair(x, y), y = j;
    }
    y = 0;
    for (int j = m; j; j--) {
      if (s[i][j] == '#') nxt[i][j][0] = make_pair(x, y), y = j;
    }
  }
  for (int i = 1; i <= m; i++) {
    int y = i, x = 0;
    for (int j = 1; j <= n; j++) {
      if (s[j][i] == '#') nxt[j][i][3] = make_pair(x, y), x = j;
    }
    x = 0;
    for (int j = n; j; j--) {
      if (s[j][i] == '#') nxt[j][i][1] = make_pair(x, y), x = j;
    }
  }

  while (!q.empty()) {
    dat p = q.top(); q.pop();
    int x = p.x, y = p.y, d = p.d;
    if (x == n) {
      return printf("%d\n", dis[x][y][d]), 0;
    }
    for (int dd = 0; dd < 4; dd++) {
      if (abs(dd - d) == 2) continue;
      int tp = dis[x][y][d] + ((dd - d) & 1);
      int xx = nxt[x][y][dd].first, yy = nxt[x][y][dd].second;
      //printf("%d %d %d\n", xx, yy, dd);
      if (xx && yy && min(dis[xx][yy][dd], dis[xx][yy][(dd + 2) % 4]) > tp) {
        dis[xx][yy][dd] = tp; q.push(dat(xx, yy, dd));
      }
    }
  }
  puts("-1");
}