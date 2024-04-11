#include <cstdio>

int K, D;
int main() {
  scanf("%d %d", &K, &D);
  if (D == 0) {
    if (K > 1) {
      printf("No solution\n");
      return 0;
    }
  }
  printf("%d", D);
  for(int i = 1; i < K; ++i) {
    printf("0");
  }
  printf("\n");
  return 0;
}