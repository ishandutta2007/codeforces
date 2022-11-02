#include <bits/stdc++.h>

const int max_N = 2000 + 21;

int n, a[max_N], ans;

std::unordered_set<int> set;

void solve() {
  set.clear();
  for (int i = 1; i <= n; ++i) {
    if (set.count(a[i])) {
      break;
    }
    set.insert(a[i]);
    int j = n + 1;
    while (j - 1 > i && !set.count(a[j - 1])) {
      set.insert(a[--j]);
    }
    ans = std::min(ans, j - i - 1);
    for (; j <= n; ++j) {
      set.erase(a[j]);
    }
  }
}

int main() {
  scanf("%d", &n);
  ans = n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  solve();
  std::reverse(a + 1, a + 1 + n);
  solve();
  printf("%d\n", ans);
}