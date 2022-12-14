#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int main() {
  int n;
  static char sy[200005];
  scanf("%d%s", &n, sy);
  vector<int> y(n), d(n + 1);
  for (int i = 0; i < n; ++i)
    y[i] = sy[i] - '0';
  for (int i = 1; i <= n; ++i)
    ++d[gcd(i, n)];
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (d[i]) {
      vector<int> sum(i);
      for (int j = 0; j < n; ++j)
        sum[j % i] ^= y[j];
      if (count(sum.begin(), sum.end(), 0) == i)
        ans += d[i];
    }
  printf("%d\n", ans);
  return 0;
}