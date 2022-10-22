#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

void work() {
  int n, x[3], y[3], X , Y;
  scanf("%d" , &n);
  std::map<int, int> xx, yy;
  int cx = -1, cy = -1;
  for (int i = 0 ; i < 3 ; ++ i) {
    scanf("%d%d" , x + i, y + i);
    if (xx[x[i]] ++) {
      cx = x[i];
    }
    if (yy[y[i]] ++) {
      cy = y[i];
    }
  }
  scanf("%d%d" , &X , &Y);
  if (X == cx || Y == cy) {
    puts("YES");
  } else {
    if ((cx == 1 || cx == n) && (cy == 1 || cy == n)) {
      puts("NO");
    } else {
      int u = (cx - X) & 1;
      int v = (cy - Y) & 1;
      puts(u && v ? "NO" : "YES");
    }


  }


}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ ca);
    work();
  }
  return 0;
}