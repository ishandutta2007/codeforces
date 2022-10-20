#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 2 && k == 1) puts("-1");
    else if (n == 4 && k == 3) puts("-1");
    else if (k == n - 1) {
      printf("%d %d\n", n - 1, n - 2);
      printf("%d %d\n", 1, n - 3);
      for (int i = 3; i < n / 2; ++i)
        printf("%d %d\n", i, n - 1 - i);
      puts("0 2");
    }
    else if (k == 0) {
      for (int i = 0; i < n / 2; ++i)
        printf("%d %d\n", i, n - 1 - i);
    }
    else {
      printf("%d %d\n", n - 1, k);
      printf("%d %d\n", 0, n - 1 - k);
      for (int i = 1; i < n / 2; ++i)
        if (i != k && i != n - 1 - k)
          printf("%d %d\n", i, n - 1 - i);
    }
  }
}