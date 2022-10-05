#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int t, n;
struct node {
  int l, r, dex;
} a[maxn];
int vis[maxn];
bool cmp(node a, node b) { return a.dex < b.dex; }
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof vis);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].l, &a[i].r);
      a[i].dex = a[i].r - a[i].l + 1;
    }
    sort(a + 1, a + 1 + n, cmp);
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
      int x = a[i].dex;
      for (int j = a[i].l; j <= a[i].r; j++) {
        if (!vis[j]) {
          vis[j] = 1;
          printf("%d %d %d\n", a[i].l, a[i].r, j);
          break;
        }
      }
    }
  }
  return 0;
}