#include <bits/stdc++.h>
using namespace std;
#define N 101010

int n, a[N];

int main() {
 // freopen("c.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  int x = 0;
  for (int i = 1; i < n; i ++) {
    if (a[i] != a[i+1]) {
      if (a[i] > a[i+1]) for (int j = 1; j <= n; j ++) a[j] = -a[j];
      x = i; break;
    }
  }
  if (x == 0) {
    puts("0"); return 0;
  }
  int y = 0;
  for (int i = x + 1; i < n; i ++) {
    if (a[i] > a[i+1]) {y = i; break;}
  }
  if (!y) puts("0");
  else printf("3\n%d %d %d\n", x, y, y + 1);
  return 0;
}