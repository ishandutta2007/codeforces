#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
//  freopen("a.in", "r", stdin);
  scanf("%d %d", &n, &m);
  printf("%d\n", n + m - 1);
  for (int i = 1; i <= n; i ++) printf("%d %d\n", i, 1);
  for (int i = 2; i <= m; i ++) printf("%d %d\n", 1, i);
  return 0;
}