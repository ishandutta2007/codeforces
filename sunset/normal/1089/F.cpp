#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 2; i * i < n; ++i) {
    if (n % i == 0 && __gcd(i, n / i) == 1) {
      int x = i, y = n / i;
      for (int a = 1; a < x; ++a) {
        if ((n - 1 - a * y) % x == 0) {
          int b = (n - 1 - a * y) / x;
          puts("YES");
          puts("2");
          printf("%d %d\n", a, x);
          printf("%d %d\n", b, y);
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}