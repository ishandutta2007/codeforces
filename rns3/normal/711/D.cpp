#include <bits/stdc++.h>
using namespace std;
#define N 200200

const int mod = 1e9 + 7;

int n, nxt[N], C, col[N], dp[N], cnt[N], gas[N];
vector <int> prv[N];

typedef long long LL;

LL expmod(LL a, LL b) {
  LL rlt = 1, x = a;
  while (b) {
    if (b & 1) rlt = rlt * x % mod;
    x = x * x % mod, b >>= 1;
  }
  return rlt;
}

void dfs(int x, int deep) {
  col[x] = C;
  dp[x] = deep;

  int y = nxt[x];
  if (col[y]) {
    if (!cnt[C]) cnt[C] = dp[x] - dp[y] + 1;
  }
  else dfs(y, deep + 1);

  for (int i = 0; i < prv[x].size(); i ++) {
    int z = prv[x][i];
    if (col[z]) continue;
    dfs(z, deep + 1);
  }
}

int main() {
 // freopen("d.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1, j; i <= n; i ++) {
    scanf("%d", &j);
    nxt[i] = j;
    prv[j].push_back(i);
  }
  C = 0;
  for (int i = 1; i <= n; i ++) {
    if (col[i]) continue;
    C ++;
    dfs(i, 0);
  }
  for (int i = 1; i <= n; i ++) gas[col[i]] ++;
  LL ans = 1;
  for (int i = 1; i <= C; i ++) {
    ans = ans * (expmod(2, cnt[i]) - 2) % mod * expmod(2, gas[i] - cnt[i]) % mod;
  }
  ans = (ans + mod) % mod;
  printf("%I64d\n", ans);
  return 0;
}