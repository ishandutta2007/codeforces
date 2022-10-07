#include <cstdio>

const int MAXN = 2010;
const int MOD = 1E9 + 7;

void add(int &a, int b) {
  a += b;
  while (a > MOD) a -= MOD;
}

int DP[MAXN][4 * MAXN][2];
int ar[MAXN];
int N, K;
int targ;

int getdp(int x, int cur, int won) {
  if (cur >= targ) won = 1;
  if (x == N) return won;
  int &ret = DP[x][cur][won];
  if (ret) return ret - 1;

  int choice1 = getdp(x + 1, cur + 2, won);
  int cur2 = 4;
  if (cur % 4 == 0) cur2 = cur + 4;
  int choice2 = getdp(x + 1, cur2, won);

  if (ar[x] != 4) add(ret, choice1);
  if (ar[x] != 2) add(ret, choice2);
  return ret++;
}

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  targ = 1 << K;

  int ans = getdp(0, 0, 0);
  printf("%d\n", ans);
}