#include <bits/stdc++.h>

void solve() {
  int a, b, p, q;
  scanf("%d%d%d%d", &a, &b, &p, &q);
  if ((long long) b * p == (long long) q * a) {
    puts("0");
    return;
  }
  if (p == q || p == 0) {
    puts("-1");
    return;
  }
  int k = std::max((a + p - 1) / p, (b - a + q - p - 1) / (q - p));
  long long ans = (long long) q * k - b;
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}