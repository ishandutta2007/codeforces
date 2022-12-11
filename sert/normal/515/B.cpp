#include <cstdio>
bool b[123], g[123];
int n, m, k, x, gg, bb;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &x);
    b[x] = true;
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &x);
    g[x] = true;
  }
  for (int i = 0; i < 10000000; i++) {
    bb = i % n;
    gg = i % m;
    b[bb] |= g[gg];
    g[gg] |= b[bb];
  }
  for (int i = 0; i < n; i++) if (!b[i]) {printf("No"); return 0;}
  for (int i = 0; i < m; i++) if (!g[i]) {printf("No"); return 0;}
  printf("Yes");
}