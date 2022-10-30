#include <bits/stdc++.h>
using namespace std;
#define M 10000
int pos[M], a[M];
int n, K, m;

int main() {
  //freopen("B.in", "r", stdin);
  int x;
  scanf("%d %d %d", &n, &K, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x), a[i] = x; pos[x] = i;
  }

  int tot = 0;
  for (int pn = 0; pn < n; pn++) {
    for (int tn = 0; tn < K; tn++) {
      scanf("%d", &x); tot += pos[x];
      int cur = pos[x];
      for (int i = pos[x]; i > 1; i--) a[i] = a[i-1];
      a[1] = x;
      for (int i = 1; i <= cur; i++) pos[a[i]] = i;
    }
  }
  printf("%d\n", tot);
}