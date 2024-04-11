#include <cstdio>

const int MAXN = 110;

int N, M;

int A[MAXN];
int B[MAXN];

bool go(int x) {
  bool one = false;
  for(int i = 0; i < N; ++i) {
    if (A[i] * 2 <= x) one = true;
    if (A[i] > x) return false;
  }
  for(int i = 0; i < M; ++i) {
    if (B[i] <= x) return false;
  }
  return one;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; ++i) {
    scanf("%d", A + i);
  }
  for(int i = 0; i < M; ++i) {
    scanf("%d", B + i);
  }

  for(int i = 0; i <= 100; ++i) {
    if (go(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}