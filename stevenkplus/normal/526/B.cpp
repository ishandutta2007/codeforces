#include <cstdio>

const int MAXN = 10100;
int ar[MAXN];
int N;

int main() {
  scanf("%d", &N);
  int M = 1 << (N + 1);
  for(int i = 2; i < M; ++i) {
    scanf("%d", ar + i);
  }

  int ans = 0;
  for(int i = M - 1; i > 1; --i) {
    int j = i ^ 1;
    if (ar[i] < ar[j]) {
//      printf("adding %d to %d\n", ar[j] - ar[i], i);
      ans += ar[j] - ar[i];
      ar[i] = ar[j];
    }

    if ((i & 1) == 0) {
      ar[i / 2] += ar[i];
    }
  }

  printf("%d\n", ans);
  return 0;
}