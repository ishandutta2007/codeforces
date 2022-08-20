#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 1005;

int n, m, a[N], b[N];

bool update(ld &mid, int coef) {
  ld need = (mid + m) / coef;
  if (mid < need) {
    return true;
  }
  mid -= need;
  return false;
}

bool check(ld mid) {
  for (int i = 1; i <= n; ++i) {
    if (update(mid, a[i]) || update(mid, b[i % n + 1])) {
      return false;
    }
  }
  return true;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  if (!check(1e9 + 1)) {
    puts("-1");
  } else {
    ld l = 0, r = 1e9;
    while (r - l > 1e-7) {
      ld mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    printf("%.9lf\n", (double)r);
  }
  return 0;
}