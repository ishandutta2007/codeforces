#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int t;
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
signed main() {
  t = read();
  while (t--) {
    int xa = read(), ya = read(), xb = read(), yb = read(), xf = read(),
        yf = read();
    if (xa != xb && ya != yb) {
      printf("%d\n", abs(xa - xb) + abs(ya - yb));
    } else if (xa != xb) {
      if (yf == ya && (min(xa, xb) < xf && xf < max(xa, xb)))
        printf("%d\n", abs(xb - xa) + 2);
      else
        printf("%d\n", abs(xb - xa));
    } else {
      if (xf == xa && (min(ya, yb) < yf && yf < max(ya, yb)))
        printf("%d\n", abs(ya - yb) + 2);
      else
        printf("%d\n", abs(ya - yb));
    }
  }
  return 0;
}