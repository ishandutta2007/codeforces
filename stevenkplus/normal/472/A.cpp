#include <cstdio>
int N;
int main() {
  scanf("%d", &N);

  if (N % 2 == 0) {
    printf("%d %d\n", 4, N - 4);
  } else {
    printf("%d %d\n", 9, N - 9);
  }
}