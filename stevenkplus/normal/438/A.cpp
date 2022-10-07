#include <cstdio>

const int MAXN = 2010;
int ar[MAXN];
int N, M;

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", ar + i);
  }

  int sum = 0;
  for(int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    int val = ar[a];
    if (ar[b] < val) val = ar[b];
    sum += val;
  }
  printf("%d\n", sum);
  return 0;
}