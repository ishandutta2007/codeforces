#include <cstdio>

const int MOD = 1E9 + 7;
const int MAXN = 1010;
const int MAXK = 55;

int N, T;

int dp[MAXN][MAXN]; // dp[K][N][prv] = #ways where last == prv
int rsums[MAXN][MAXN];
int ssums[MAXN][MAXN];

int ans[MAXK][MAXN]; // sum dp[K][N][1..N] * K!

long long f[MAXK];

int main() {
  f[0] = 1;
  for(int i = 0; i + 1 < MAXK; ++i) {
    f[i + 1] = f[i] * (i + 1) % MOD;
  }

  for(int i = 0; i < MAXN; ++i) {
    dp[i][0] = 1;
  }

  for(int k = 0; k  + 1 < MAXK; ++k) {
    for(int i = 0; i < MAXN; ++i) {
      ssums[i][0] = ssums[0][i] = 0;
    }
    for(int i = 0; i < MAXN; ++i) {
      rsums[i][0] = 0;
      for(int j = 0; j + 1 < MAXN; ++j) {
        (rsums[i][j + 1] = rsums[i][j] + dp[i][j]) %= MOD;
        (ssums[i + 1][j + 1] = ssums[i][j + 1] + rsums[i][j + 1]) %= MOD;
      }
    }

    for(int i = 0; i < MAXN; ++i) {
      for(int j = 0; j <= i; ++j) {
        dp[i][j] = ssums[i - j + 1][j];
        (ans[k + 1][i] += dp[i][j]) %= MOD;
      }
      for(int j = i + 1; j < MAXN; ++j) {
        dp[i][j] = 0;
      }
    }
  }

  scanf("%d", &T);
  for(int t = 0; t < T; ++t) {
    int a, b;
    scanf("%d %d", &b, &a);
    if (a >= MAXK) {
      printf("0\n");
    } else {
      int p = ans[a][b];
      p = p * f[a] % MOD;
      printf("%d\n", p);
    }
  }
  return 0;
}