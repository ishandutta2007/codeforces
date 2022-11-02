#include <bits/stdc++.h>
using namespace std;
#define M 110
int a[M][M], b[M][M], c[M][M], n, m, cap, ans;

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d", &n, &m, &cap);
  char s[100];
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) {
      scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      multiset <pair <int, int> > setv;
      for (int k = 0; k < m; k++) {
        setv.insert(make_pair(b[i][k] - a[j][k], c[j][k]));
      }
      int res = 0, tot = 0;
      while (!setv.empty()) {
        pair <int, int> p = *--setv.end();
        setv.erase(--setv.end());
        if (p.first <= 0) break;
        res += p.first * min(cap - tot, p.second);
        tot += p.second; if (tot >= cap) break;
      }
      //if (res == 19) printf("%d %d\n", i, j);
      ans = max(ans, res);
    }
  }
  printf("%d\n", ans);
}