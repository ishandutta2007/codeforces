#include <bits/stdc++.h>
using namespace std;
#define INF (1LL << 60)
typedef long long LL;

int n, m, Q;

struct dat {
  int x, y; LL t;
  dat (int x = 0, int y = 0, LL t = 0) : x(x), y(y), t(t) {}
} ;

map <int, dat> T[5];

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d", &n, &m, &Q);

  int x = 0, y = 0, dir = 0, ex, ey;
  LL cur = 0;

  while (1) {
    if ((!x && y == m) || (x == n && !y) || (x == n && y == m)) break;
    if (!dir) {
      T[0][y - x] = dat(x, y, cur);
      if (y - x <= m - n) ex = n, ey = n + y - x, dir = 3;
      else ey = m, ex = m + x - y, dir = 1;
      cur += abs(ex - x);
    }
    else if (dir == 1) {
      T[1][x + y] = dat(x, y, cur);
      if (x + y <= n) ex = x + y, ey = 0, dir = 0;
      else ex = n, ey = x + y - n, dir = 2;
      cur += abs(ex - x);
    }
    else if (dir == 2) {
      T[2][y - x] = dat(x, y, cur);
      if (y <= x) ex = x - y, ey = 0, dir = 3;
      else ex = 0, ey = y - x, dir = 1;
      cur += abs(ex - x);
    }
    else {
      T[3][x + y] = dat(x, y, cur);
      if (x + y <= m) ex = 0, ey = x + y, dir = 0;
      else ex = x + y - m, ey = m, dir = 2;
      cur += abs(ex - x);
    }
    x = ex, y = ey;
  }

  while (Q--) {
    LL ans = INF;
    scanf("%d %d", &x, &y);
    if (T[0].count(y - x)) {
      dat p = T[0][y - x];
      LL tmp = p.t;
      tmp += abs(x - p.x);
      ans = min(ans, tmp);
    }
    if (T[1].count(x + y)) {
      dat p = T[1][x + y];
      LL tmp = p.t;
      tmp += abs(x - p.x);
      ans = min(ans, tmp);
    }
    if (T[2].count(y - x)) {
      dat p = T[2][y - x];
      LL tmp = p.t;
      tmp += abs(x - p.x);
      ans = min(ans, tmp);
    }
    if (T[3].count(x + y)) {
      dat p = T[3][x + y];
      LL tmp = p.t;
      tmp += abs(x - p.x);
      ans = min(ans, tmp);
    }
    if (ans == INF) puts("-1");
    else {
      cout << ans << endl;
    }
  }
}