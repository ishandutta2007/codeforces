#include <bits/stdc++.h>
using namespace std;
#define N 1010

int a, b, dx, dy, xx[N], yy[N];
char s[N];

bool ok(int c, int d) {
  if (!dx && !dy) {
    return (c == 0 && d == 0) ? 1 : 0;
  }
  if (!dx) {
    return (c == 0 && d % dy == 0 && d / dy >= 0) ? 1 : 0;
  }
  if (!dy) {
    return (d == 0 && c % dx == 0 && c / dx >= 0) ? 1 : 0;
  }
  return (c % dx == 0 && d % dy == 0 && c / dx == d / dy && c / dx >= 0) ? 1 : 0;
}

int main() {
 // freopen("c.in", "r", stdin);
  scanf("%d %d %s", &a, &b, s);
  int len = strlen(s);
  int x = 0, y = 0;
  if (x == a && y == b) {
    puts("Yes"); return 0;
  }
  for (int i = 0; i < len; i ++) {
    if (s[i] == 'U') y ++;
    else if (s[i] == 'D') y --;
    else if (s[i] == 'R') x ++;
    else x --;
    xx[i] = x, yy[i] = y;
  }
  dx = xx[len-1], dy = yy[len-1];
  for (int i = 0; i < len; i ++) {
    if (ok(a - xx[i], b - yy[i])) {
      puts("Yes"); return 0;
    }
  }
  puts("No");
  return 0;
}