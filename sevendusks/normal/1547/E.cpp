#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int t, n, k, a[300001], b[300001], c[300001], ans[300001];
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
inline void ckmin(int &x, int y) {
  if (x > y) x = y;
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    k = read();
    std::memset(a + 1, 0x3f, 4 * n);
    std::memset(b + 1, 0x3f, 4 * n);
    std::memset(c + 1, 0x3f, 4 * n);
    std::memset(ans + 1, 0x3f, 4 * n);
    for (int i = 1; i <= k; i++) a[i] = read();
    for (int i = 1; i <= k; i++) b[i] = read();
    for (int i = 1; i <= k; i++) c[a[i]] = b[i];
    int min = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      min++;
      ckmin(min, c[i]);
      ckmin(ans[i], min);
    }
    min = 0x3f3f3f3f;
    for (int i = n; i >= 1; i--) {
      min++;
      ckmin(min, c[i]);
      ckmin(ans[i], min);
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
  }
  return 0;
}