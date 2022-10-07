#include <cstdio>

const int MAXN = 2010;
const int MOD = 1E9 + 7;

int DP[MAXN][MAXN];

void add(int &a, int b) {
  a += b;
  while (a >= MOD) {
    a -= MOD;
  }
}

int N, K;

int getdp(int pos, int prv) {
  if (pos == K) return 1;
  int &ret = DP[pos][prv];
  if (ret) return ret - 1;

  for(int choice = prv; choice <= N; choice += prv) {
    add(ret, getdp(pos + 1, choice));
  }

  return ret++;
}

int main() {
  scanf("%d %d", &N, &K);
  int ans = getdp(0, 1);
  printf("%d\n", ans);
  return 0;
}