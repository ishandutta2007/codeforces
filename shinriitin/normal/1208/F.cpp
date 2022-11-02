#include <bits/stdc++.h>

const int max_N = (int)4e6 + 21;

int n, a[max_N], cnt[max_N], ans;

#define lbt(x) ((x) & -(x))

void solve(int u, int v) {
  int &cnt_ = cnt[u ^ v];
  if (cnt_ > 1)
    return;
  ++cnt_;
  for (; v; v -= lbt(v)) {
    solve(u, v - lbt(v));
    u |= lbt(v);
  }
}

int query(int i) {
  int ans = 0;
  for (int j = 20; ~j; --j) {
    if (((a[i] >> j) & 1))
      continue;
    if (cnt[ans | (1 << j)] > 1) {
      ans |= (1 << j);
    }
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = n; i; --i) {
    solve(0, a[i]);
    ans = std::max(ans, query(i) | a[i]);
  }
  printf("%d\n", ans);
}