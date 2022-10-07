#include <cstdio>
#include <cmath>

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int c = gcd(a, b);
  int x = a / c, y = b / c;

  int sol = -1;
  for(int i = 1; i < c; ++i) {
    int j = sqrt(c * c - i * i);
    if (i * i + j * j == c * c) {
      sol = i;
      break;
    }
  }

  if (sol == -1) {
    printf("NO\n");
  } else {
    printf("YES\n");
    printf("0 0\n");
    int m = sol, n = sqrt(c * c - m * m);
    printf("%d %d\n", x * m, x * n);
    if (x * n == y * m) {
      printf("%d %d\n", x * m - y * n, x * n + y * m);
    } else {
      printf("%d %d\n", x * m + y * n, x * n - y * m);
    }
  }
  return 0;
}