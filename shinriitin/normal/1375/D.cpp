#include <bits/stdc++.h>

const int max_N = 2000 + 21;

int T, n, a[max_N], cnt[max_N], ans[max_N], tot;

int mex() {
  std::fill_n(cnt, n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    ++cnt[a[i]];
  }
  for (int i = 0; i <= n; ++i) {
    if (!cnt[i]) {
      return i;
    }
  }
  assert(0);
}

bool check() {
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  tot = 0;
  while (!check()) {
    int x = mex();
    if (x == n) {
      for (int i = n; i; --i) {
        if (a[i] != i - 1) {
          ans[++tot] = i;
          a[i] = x;
          break;
        }
      }
    } else {
      ans[++tot] = x + 1;
      a[x + 1] = x;
    }
//    for (int i = 1; i <= n; ++i) {
//      printf("%d%c", a[i], " \n"[i == n]);
//    }
  }
  printf("%d\n", tot);
  for (int i = 1; i <= tot; ++i) {
    printf("%d%c", ans[i], " \n"[i == tot]);
  }
  if (!tot) {
    puts("");
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}