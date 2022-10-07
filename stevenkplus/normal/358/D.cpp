#include <cstdio>

const int MAXN = 3010;

int DP[MAXN][2];
int ar[MAXN][3];
int N;

int go(int cur, int prv) {
  int &ret = DP[cur][prv];
  if (ret) return ret - 1;
  if (cur == N - 1) {
    ret = ar[cur][prv];
  } else {
    for(int ch = 0; ch < 2; ++ch) {
      int val = ar[cur][ch + prv] + go(cur + 1, 1 - ch);
      if (val > ret) ret = val;
    }
  }

  return ret++;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < N; ++j) {
      scanf("%d", ar[j] + i);
    }
  }

  int ans = go(0, 0);
  printf("%d\n", ans);
  return 0;
}