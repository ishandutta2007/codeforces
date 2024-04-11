#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int t, n, m, k, a[101], b[101];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
signed main() {
  t = read();
  while (t--) {
    k = read();
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) b[i] = read();
    int p1 = 1, p2 = 1;
    bool ok = true;
    vector<int> ans;
    while (p1 <= n || p2 <= m) {
      bool f = false;
      if (p1 <= n && a[p1] <= k) {
        f = true;
        ans.emplace_back(a[p1]);
        if (!a[p1++]) k++;
        continue;
      }
      if (p2 <= m && b[p2] <= k) {
        f = true;
        ans.emplace_back(b[p2]);
        if (!b[p2++]) k++;
        continue;
      }
      if (!f) {
        ok = false;
        break;
      }
    }
    if (!ok)
      printf("-1\n");
    else
      for (int i = 0; i < n + m; i++)
        printf("%d%c", ans[i], " \n"[i == n + m - 1]);
  }
  return 0;
}