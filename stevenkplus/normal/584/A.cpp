#include <cstdio>

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  if (t == 10 && n == 1) {
    printf("-1\n");
    return 0;
  }
  if (t == 10) {
    t = 1;
  }

  for(int i = 0; i < n; ++i) {
    if (i == 0)
      printf("%d", t);
    else
      printf("0");
  }
  printf("\n");
}