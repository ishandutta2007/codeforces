#include <cstdio>

int N;

int dist(int x, int y, int a, int b) {
  a -= x;
  b -= y;
  if (a < 0) a = -a;
  if (b < 0) b = - b;
  return a + b;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (dist(i, j, N / 2, N / 2) <= N / 2) {
        printf("D");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
}