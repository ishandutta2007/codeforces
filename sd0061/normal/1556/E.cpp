#include <bits/stdc++.h>
using int64 = long long;
const int N = 100005;

int n, m, a[N];
int64 s[N];
int64 mx[17][N], mn[17][N];
int LOG[N];

std::pair<int64, int64> find(int l, int r) {
  int s = LOG[r - l + 1];
  int64 min = std::min(mn[s][l], mn[s][r - (1 << s) + 1]);
  int64 max = std::max(mx[s][l], mx[s][r - (1 << s) + 1]);
  return {min, max};
}

void work() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] -= x;
  }
  for (int i = 0; 1 << i <= n; ++i) {
    LOG[1 << i] = i;
  }
  for (int i = 2; i <= n; ++i) {
    if (!LOG[i]) {
      LOG[i] = LOG[i - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] += x;
  }
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + a[i];
  }
  for (int i = 0; i <= n; ++i) {
    mn[0][i] = mx[0][i] = s[i];
  }
  for (int j = 1; 1 << j <= n; ++j) {
    for (int i = 0; i + (1 << j) - 1 <= n; ++i) {
      mn[j][i] = std::min(mn[j - 1][i], mn[j - 1][i + (1 << j - 1)]);
      mx[j][i] = std::max(mx[j - 1][i], mx[j - 1][i + (1 << j - 1)]);
    }
  }

  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    --r;
    if (s[r + 1] != s[l]) {
      puts("-1");
    } else {
      auto [min, max] = find(l + 1, r + 1);
      if (min < s[l]) {
        puts("-1");
      } else {
        printf("%lld\n", max - s[l]);
      }
    }
  }
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}