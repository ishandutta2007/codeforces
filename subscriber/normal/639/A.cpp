#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int w[N], a[N];

int main() {
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", w + i);
  }
  w[n] = -1;
  for (int i = 0; i < k; i++) {
    a[i] = n;
  }
  for (int i = 0; i < q; i++) {
    int type, v;
    scanf("%d %d", &type, &v);
    v--;
    if (type == 1) {
      int pos = 0;
      for (int u = 1; u < k; u++) {
        if (w[a[u]] < w[a[pos]]) {
          pos = u;
        }
      }
      if (w[a[pos]] < w[v]) {
        a[pos] = v;
      }
    } else {
      bool ok = false;
      for (int u = 0; u < k; u++) {
        if (a[u] == v) {
          ok = true;
          break;
        }
      }
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}