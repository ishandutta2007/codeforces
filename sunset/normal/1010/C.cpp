#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  int gcd = m;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    x %= m;
    gcd = __gcd(gcd, x);
  }
  printf("%d\n", m / gcd);
  for (int i = 0; i < m; i += gcd) {
    printf("%d%c", i, i == m - gcd ? '\n' : ' ');
  }
  return 0;
}