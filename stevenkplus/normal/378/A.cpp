#include <cstdio>
#include <cstdlib>
#include <cmath>

int a, b;

int main() {
  scanf("%d %d", &a, &b);
  int x = 0, y = 0, z = 0;
  for(int i = 1; i <= 6; ++i) {
    int d1 = abs(i - a);
    int d2 = abs(i - b);
    if (d1 < d2) ++x;
    else if (d1 == d2) ++y;
    else ++z;
  }

  printf("%d %d %d\n", x, y, z);
}