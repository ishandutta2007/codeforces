#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int t[N][2];
int d[N];
int ans[N], cnt = 0;

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(t, 0, 8 * n + 8);
  memset(d, 0, 4 * n + 4);
  for (int i = 1, u; i <= m; ++i) {
    scanf("%d", &u);
    scanf("%d", t[u] + bool(t[u][0]));
  }
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == 2) ans[++cnt] = i, d[i] = -1;
    d[t[i][0]] = max(d[t[i][0]], d[i] + 1);
    d[t[i][1]] = max(d[t[i][1]], d[i] + 1);
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i)
    printf("%d%c", ans[i], " \n"[i == cnt]);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}