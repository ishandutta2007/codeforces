#include <bits/stdc++.h>
using int64 = long long;

const int N = (1 << 19) + 5;

int n, k, a[N];

struct Node {
  int min, max, ans;
};

Node f[2][N];

void work() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[x] = 1;
  }
  int cur = 0, nxt = 1;
  for (int i = 0; i < 1 << k; ++i) {
    f[cur][i].ans = N;
    if (a[i]) {
      f[cur][i].min = i;
      f[cur][i].max = i;
    } else {
      f[cur][i].min = N;
      f[cur][i].max = -N;
    }
  }
  for (int j = 0; j < k; ++j) {
    for (int i = 0; i < 1 << k; ++i) {
      Node left = f[cur][i], right = f[cur][i ^ (1 << j)];
      if (i >> j & 1) {
        if (left.min < N) {
          left.min -= 1 << j;
          left.max -= 1 << j;
        }
        if (right.min < N) {
          right.min += 1 << j;
          right.max += 1 << j;
        }
      }
      f[nxt][i].min = std::min(left.min, right.min);
      f[nxt][i].max = std::max(left.max, right.max);
      f[nxt][i].ans = std::min(left.ans, right.ans);
      if (right.min < N && left.max >= 0) {
        f[nxt][i].ans = std::min(f[nxt][i].ans, right.min - left.max);
      }
    }
    std::swap(cur, nxt);
  }
  for (int i = 0; i < 1 << k; ++i) {
    printf("%d%c", f[cur][i].ans, " \n"[i + 1 == (1 << k)]);
  }
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}