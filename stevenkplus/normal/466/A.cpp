#include <cstdio>

int main() {
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  int way1 = n * a;
  int way2 = (n / m) * b + (n % m) * a;
  int way3 = (n + m - 1) / m * b;
  int ans = way1;
  if (way2 < ans) ans = way2;
  if (way3 < ans) ans = way3;
  printf("%d\n", ans);
}