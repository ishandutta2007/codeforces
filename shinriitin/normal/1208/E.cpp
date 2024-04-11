#include <bits/stdc++.h>

const int max_N = (int)1e6 + 21;

int n, w, a[max_N], Q[max_N], head, tail, L[max_N], R[max_N];

long long ans[max_N];

int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1, m; i <= n; ++i) {
    scanf("%d", &m);
    int k = w - m;
    head = 1, tail = 0;
    for (int j = 1; j <= m; ++j) {
      scanf("%d", a + j);
      L[j] = 0;
      R[j] = j + k;
      while (head <= tail && a[Q[tail]] <= a[j]) {
        R[Q[tail--]] = j - 1;
      }
      Q[++tail] = j;
      while (head <= tail && Q[head] + k < j) {
        R[Q[head++]] = j - 1;
      }
      if (!L[Q[head]]) { L[Q[head]] = j; }
    }
    while (head < tail) {
      L[Q[head + 1]] = R[Q[head]] + 1;
      ++head;
    }
    for (int j = 1; j <= m; ++j) {
      if (!L[j]) continue;
      if (a[j] >= 0) {
        ans[L[j]] += a[j];
        ans[R[j] + 1] -= a[j];
      } else {
        L[j] = std::max(L[j], k + 1);
        R[j] = std::min(R[j], w - k);
        if (L[j] <= R[j]) {
          ans[L[j]] += a[j];
          ans[R[j] + 1] -= a[j];
        }
      }
    }
  }
  for (int i = 1; i <= w; ++i) {
    ans[i] += ans[i - 1];
    printf("%lld%c", ans[i], " \n"[i == w]);
  }
}