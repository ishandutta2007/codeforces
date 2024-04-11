#include <bits/stdc++.h>

int main() {
  int h1, a1, d1;
  int h2, a2, d2;
  scanf("%d%d%d%d%d%d", &h1, &a1, &d1, &h2, &a2, &d2);
  int h, a, d;
  scanf("%d%d%d", &h, &a, &d);
  int ans = 1 << 30;
  for (int d0 = 0; d0 <= 222; d0++) {
    for (int a0 = 0; a0 <= 222; a0++) {
      if (d * d0 + a * a0 > ans) continue;
      int d3 = d1 + d0;
      int a3 = a1 + a0;
      int we = std::max(0, a3 - d2);
      if (we == 0) continue;
      int t = (h2 + we - 1) / we;
      int he = std::max(0, a2 - d3);
      int h0 = std::max(0, he * t + 1 - h1);
      int cost = h0 * h + d0 * d + a0 * a;
      if (cost < ans) ans = cost;
    }
  }
  printf("%d\n", ans);
}