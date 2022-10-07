#include <cstdio>

int n, x;

int main() {
  scanf("%d %d", &n, &x);
  int curt = 1;
  int sum = 0;

  for(int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ++b;
    int diff = a - curt;
    sum += diff % x;
    sum += b - a;
    curt = b;
  }

  printf("%d\n", sum);
}