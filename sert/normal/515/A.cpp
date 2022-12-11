#include <cstdio>

int abs(int x) {
  return (x < 0 ? -x : x);
}
int x, y, k, d;
int main() {
  scanf("%d%d%d", &x, &y, &k);
  d = abs(x) + abs(y);
  if (d > k || (k - d) % 2 == 1) 
    printf("No");
  else 
    printf("Yes");
}