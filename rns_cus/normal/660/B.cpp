#include <bits/stdc++.h>
using namespace std;
int main() {
  //freopen("in.txt", "r", stdin);
  int n, m;
  scanf("%d %d", &n, &m);
  if (m <= 2 * n) {
    for (int i = 1; i <= m; i++) printf("%d ", i);
    return 0;
  }
  int d = m - 2 * n;
  for (int i = 1; i <= d / 2; i++) {
    printf("%d %d %d %d ", 2 * n + 2 * i - 1, 2 * i - 1, 2 * n + 2 * i, 2 * i);
  }
  if (d & 1) printf("%d ", 2 * n + d);
  d = d / 2 * 2;
  for (int i = d + 1; i <= 2 * n; i++) printf("%d ", i);
}