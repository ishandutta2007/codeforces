#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 2e5 + 5;

int n;

struct point {
  int x, y;
} a[N];

double dist(point a, point b) {
  return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) +
    1.0 * (a.y - b.y) * (a.y - b.y));
}

void work() {
  double ans = 0;
  read(n);
  for (int i = 1; i <= n * 2; i++) {
  	read(a[i].x); read(a[i].y);
  	if (a[i].x < 0) a[i].x = -a[i].x;
  	if (a[i].y < 0) a[i].y = -a[i].y;
  }
  std::sort(a + 1, a + n * 2 + 1, [&](point a, point b)
    {return a.x < b.x || (a.x == b.x && a.y > b.y);});
  for (int i = 1; i <= n; i++)
    ans += dist(a[n - i + 1], a[n + i]);
  printf("%.13lf\n", ans);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}