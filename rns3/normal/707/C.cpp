#include <stdio.h>

int main() {
  //freopen("1.in", "r", stdin);
  int n;
  scanf("%d", &n);
  if(n == 1 || n == 2) {
    puts("-1");
    return 0;
  }
  int m = n;
  while(m % 2 == 0) {
    if(m == 4) break;
    m /= 2;
  }
  long long x, y;
  long long val = 1ll * m * m;
  if(m == 4) x = 3, y = 5;
  else x = (val - 1) / 2, y = x + 1;
  printf("%I64d %I64d\n", n / m * x, n / m * y);
  return 0;
}