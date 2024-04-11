#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int s[2][N];
int x[N], y[N];
int n;

inline void modify(int q, int x, int v) {
  while (x <= n) {
    s[q][x] += v;
    x += x & (-x);
  }
}

inline int find_sum(int q, int x) {
  int v = 0;
  while (x > 0) {
    v += s[q][x];
    x -= x & (-x);
  }
  return v;
}

int main() {
    //freopen("b.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
  int k, a, b, tt;
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &tt);
  for (int i = 1; i <= n; i++) {
    x[i] = 0;
    y[i] = 0;
    s[0][i] = s[1][i] = 0;
  }
  while (tt--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int day, cnt;
      scanf("%d %d", &day, &cnt);
      int new_x = min(b, x[day] + cnt);
      int new_y = min(a, y[day] + cnt);
      modify(0, day, new_x - x[day]);
      modify(1, day, new_y - y[day]);
      x[day] = new_x;
      y[day] = new_y;
    } else {
      int from;
      scanf("%d", &from);
      int to = from + k - 1;
      int ans = find_sum(0, from - 1);
      ans += find_sum(1, n) - find_sum(1, to);
      printf("%d\n", ans);
    }
  }
  return 0;
}