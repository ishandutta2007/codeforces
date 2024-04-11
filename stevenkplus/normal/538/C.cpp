#include <cstdio>

int N, M;

int abs(int x) {
  if (x > 0) {
    return x;
  } else {
    return -x;
  }
}

bool good(int a, int b, int h, int c, int d) {
  int x = abs(h - b), y = abs(h - d);
  return x + y <= c - a;
}

int main() {
  scanf("%d %d", &N, &M);
  int d, h;
  scanf("%d %d", &d, &h);
  int ans = d + h - 1;
  for(int i = 1; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (!good(d, h, h, a, b)) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
    while (good(d, h, ans + 1, a, b)) {
      ans += 1;
    }
    d = a;
    h = b;
  }

  while (good(d, h, ans + 1, N, ans + 1)) {
    ans += 1;
  }

  printf("%d\n", ans);
}