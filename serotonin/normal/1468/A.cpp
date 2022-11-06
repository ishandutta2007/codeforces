#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

vector <int> pos[N];
int tests, n, a[N], t[N << 2], f[N];

int query (int l, int r) {
  int ret = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = max(ret, t[l++]);
    if (r & 1) ret = max(ret, t[--r]);
  } return ret;
}

void update (int p, int v) {
  for (t[p += n] = v; p > 1; p >>= 1) {
    t[p >> 1] = max(t[p], t[p ^ 1]);
  }
}

int main() {
  cin >> tests;
  while (tests--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      pos[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      pos[a[i]].emplace_back(i);
    }
    for (int i = 0; i < n + n; ++i) {
      t[i] = 0;
    }
    int ans = 2;
    set <int> bigs;
    for (int i = 0; i < n; ++i) {
      bigs.emplace(i);
    }
    for (int i = 1; i <= n; ++i) {
      if (pos[i].empty()) continue;
      for (int x : pos[i]) {
        f[x] = 1 + query(0, x);
        bigs.erase(x);
        auto it = bigs.upper_bound(x);
        if (it != bigs.begin()) {
          int at = *prev(it);
          f[x] = max(f[x], 2 + query(0, at));
        }
        update(x, f[x]);
        ans = max(ans, f[x]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}