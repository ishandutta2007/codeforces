#include <cstdio>

const int MAXN = 100;

int ans[MAXN];
int N, M;

int main() {
  scanf("%d %d", &N, &M);
  --M;

  int a = 0, b = N - 1;
  int cnt = 1;
  for(int i = N - 2; i >= 0; --i) {
    if (M & (1 << i)) {
      ans[b] = cnt;
      --b;
    } else {
      ans[a] = cnt;
      ++a;
    }
    ++cnt;
  }
  ans[a] = N;

  for(int i = 0; i < N; ++i) {
    printf("%d ", ans[i]);
  }

  printf("\n");
  return 0;
}