#include <cstdio>

const int MAXN = 1001000;

int N;
int fav[MAXN];
int par[MAXN];
int dp[MAXN];

int main() {
  scanf("%d", &N);
  int ans = 0;
  for(int i = 2; i <= N + 1; ++i) {
//    printf("on %d\n", i);
    int x;
    scanf("%d", &x);
    par[i] = x;;
    x = i;
    dp[x] = 1;

    while (par[x] != 1) {
//      printf("dp[%d] = %d\n", x, dp[x]);
      int up = par[x];
      int orig = dp[up];
//      printf("fav = %d\n", fav[up]);
      if (fav[up] == x) {
        if (dp[x] > dp[up]) {
          dp[up] = dp[x];
        }
      } else {
        if (dp[x] > dp[fav[up]]) {
          fav[up] = x;
          dp[up] = dp[x];
        } else {
          if (dp[x] + 1 > dp[up]) {
            dp[up] = dp[x] + 1;
          }
        }
      }
      if (orig == dp[up]) break;
      x = up;
    }
//    printf("dp[%d] = %d\n", x, dp[x]);
    if (dp[x] > ans) ans = dp[x];

    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}