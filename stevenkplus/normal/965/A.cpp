#include <cstdio>

int main() {
  int k, n, s, p;
  scanf("%d %d %d %d", &k, &n, &s, &p);
  int needSheets = (n + s - 1) / s * k;
  int ans = (needSheets + p - 1)/ p;
  printf("%d\n", ans);
}