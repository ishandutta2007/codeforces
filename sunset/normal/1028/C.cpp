#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
  }
  vector<int> pa = a, pb = b, pc = c, pd = d;
  for (int i = 1; i < n; ++i) {
    pa[i] = max(pa[i - 1], pa[i]);
    pb[i] = max(pb[i - 1], pb[i]);
    pc[i] = min(pc[i - 1], pc[i]);
    pd[i] = min(pd[i - 1], pd[i]);
  } 
  vector<int> sa = a, sb = b, sc = c, sd = d;
  for (int i = n - 2; ~i; --i) {
    sa[i] = max(sa[i + 1], sa[i]);
    sb[i] = max(sb[i + 1], sb[i]);
    sc[i] = min(sc[i + 1], sc[i]);
    sd[i] = min(sd[i + 1], sd[i]);
  }
  if (pa[n - 2] <= pc[n - 2] && pb[n - 2] <= pd[n - 2]) {
    printf("%d %d\n", pa[n - 2], pb[n - 2]);
    return 0;
  }
  if (sa[1] <= sc[1] && sb[1] <= sd[1]) {
    printf("%d %d\n", sa[1], sb[1]);
    return 0;
  }
  for (int i = 1; i < n - 1; ++i) {
    int a = max(pa[i - 1], sa[i + 1]);
    int b = max(pb[i - 1], sb[i + 1]);
    int c = min(pc[i - 1], sc[i + 1]);
    int d = min(pd[i - 1], sd[i + 1]);
    if (a <= c && b <= d) {
      printf("%d %d\n", a, b);
      return 0;
    }
  }
  return 0;
}