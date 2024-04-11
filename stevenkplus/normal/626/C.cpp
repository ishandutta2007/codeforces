#include <cstdio>

bool can(int n, int m, int H) {
  int twos = H / 2;
  int threes = H / 3;
  int both = H / 6;
  return (n <= twos && m <= threes && n + m <= twos + threes - both);
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = -1;
  for(int i = 0; i <= 10000000; ++i) {
    if (can(a, b, i)) {
      ans = i;
      break;
    }
  }

  printf("%d\n", ans);
  return 0;
}