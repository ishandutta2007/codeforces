#include <cstdio>
#include <cstring>

const int MAXN = 110;

int N, T;

int ar[MAXN * MAXN];

int DP[330][MAXN * MAXN];

int getDP(int prv, int cur) {
  int &ret = DP[prv][cur];
  if (ret) return ret - 1;

  if (cur == N) {
    return 0;
  }
  if (ar[cur] >= prv) {
    int choice1 = getDP(ar[cur], cur + 1) + 1;
    if (choice1 > ret) ret = choice1;
  }
  int choice2 = getDP(prv, cur + 1);
  if (choice2 > ret) ret = choice2;
  return ret++;
}

int solve() {
  memset(DP, 0, sizeof(DP));
  for(int i = 0; i + N < N * T; ++i) {
    ar[i + N] = ar[i];
  }
  N *= T;

  int ans = getDP(0, 0);
  return ans;
}

int main() {
  scanf("%d %d", &N, &T);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  if (T >= N) {
    int oldT = T;
    int oldN = N;
    T = N;
    int ans1 = solve();
    N = oldN;
    T = N + 1;
    int ans2 = solve();
    N = oldN;
    T = N + 2;
    int rate = ans2 - ans1;
    int ans = ans1 + (oldT - oldN) * rate;
    printf("%d\n", ans);
  } else {
    int ans = solve();
    printf("%d\n", ans);
  }
}