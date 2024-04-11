#include <cstdio>

int N, K;

int main() {
  scanf("%d %d", &N, &K);
  if (K * 2 <= N - 1) {
    printf("%d\n", K * N);
    for(int i = 1; i <= N; ++i) {
      int j = i;
      for(int k = 1; k <= K; ++k) {
        ++j;
        if (j > N) j = 1;
        printf("%d %d\n", i, j);
      }
    }
  } else {
    printf("-1\n");
  }
  return 0;
}