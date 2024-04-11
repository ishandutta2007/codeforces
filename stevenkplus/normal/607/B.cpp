#include <cstdio>

const int MAXN = 555;
int ar[MAXN];

int DP[MAXN][MAXN];

int N;
int getDP(int l, int r) {
  /*
  (l, r) -> max((l + 1, r - 1, 1), 1) or (l, m) + (m, r)
  (x, x) -> 0
  (x, x + 1) -> 1
  */
  int &ret = DP[l][r];
  if (ret) return ret - 1;
  if (l == r) {
    ret = 0;
  } else if (l + 1 == r) {
    ret = 1;
  } else {
    ret = N;
    if (ar[l] == ar[r - 1]) {
      int cand = 1;
      if (l + 2 < r) {
        cand = getDP(l + 1, r - 1);
      }
      if (cand < ret) ret = cand;
    }
    for(int m = l + 1; m < r; ++m) {
      int cand = getDP(l, m) + getDP(m, r);
      if (cand < ret) ret = cand;
    }
  }
  return ret++;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  int ans = getDP(0, N);
  printf("%d\n", ans);
  return 0;
}