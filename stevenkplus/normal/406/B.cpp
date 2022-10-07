#include <cstdio>
const int MAXN = 1000000;
bool vis[MAXN];
bool ans[MAXN];

int N;

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    vis[x] = true;
  }

  int bad = 0;
  for(int i = 0; i < MAXN / 2; ++i) {
    if (vis[i]) {
      if (vis[MAXN - 1 - i]) {
        ++bad;
      }
    }
  }

  printf("%d\n", N);
  for(int i = 0; i < MAXN; ++i) {
    if (vis[MAXN - 1 - i] && !vis[i]) {
      printf("%d ", i + 1);
    } else if (bad && !vis[i]) {
      printf("%d %d ", i + 1, MAXN - i);
      --bad;
    }
  }
  printf("\n");

  return 0;
}