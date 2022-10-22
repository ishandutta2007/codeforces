#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x;
    scanf("%d", &x);
    int a = 0;
    while (x > 0) {
      a = std::max(a, x % 10);

      x /= 10;
    }
    printf("%d\n", a);
  }
  return 0;
}