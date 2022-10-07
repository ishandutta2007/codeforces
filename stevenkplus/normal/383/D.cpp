#include <cstdio>

const int MAXN = 1100;
const int MAXV = 10100;
const int MOD = 1E9 + 7;

int _DP[MAXN][MAXV * 2];
int *DP[MAXN];

int N;
int ar[MAXN];

int go(int a, int b) {
  int &ret = DP[a][b];
  if (ret) return ret - 1;

  if (b == 0) ret = 1;
  if (a < N) {
    (ret += go(a + 1, b + ar[a])) %= MOD;
    (ret += go(a + 1, b - ar[a])) %= MOD;
  }

  return ret++;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  for(int i = 0; i < MAXN; ++i) {
    DP[i] = _DP[i] + MAXV;
  }

  int ans = 0;
  for(int i = 0; i < N; ++i) {
    (ans += go(i, 0) - 1) %= MOD;
  }

  if (ans < 0) ans += MOD;

  printf("%d\n", ans);
  return 0;
}