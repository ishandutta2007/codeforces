#include <bits/stdc++.h>
using namespace std;
#define inf 100000000

int n;

int step(int n, int m) {
  if (!m) return inf;
  if (m == 1) return n - 1;
  return step(m, n % m) + n / m;
}

int main() {
  scanf("%d", &n);
  int ans = inf;
  for (int i = 1; i <= n; i ++) ans = min(ans, step(n, i));
  printf("%d\n", ans);
  return 0;
}