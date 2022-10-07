#include <cstdio>

const int MAXN = 1111;
char str[MAXN];

int N, K;

int main() {
  scanf("%d %d", &N, &K);
  scanf("%s", str);
  int d1 = K - 1;
  int d2 = N - K;
  if (d1 < d2) {
    while (K != 1) {
      printf("LEFT\n");
      --K;
    }
    for(int i = 0; i < N; ++i) {
      printf("PRINT %c\n", str[i]);
      if (i + 1 < N) printf("RIGHT\n");
    }
  } else {
    while (K != N) {
      printf("RIGHT\n");
      ++K;
    }
    for(int i = N - 1; i >= 0; --i) {
      printf("PRINT %c\n", str[i]);
      if (i - 1 >= 0) printf("LEFT\n");
    }
  }

  return 0;
}