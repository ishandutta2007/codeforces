#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, a[N];

int main() {
 // freopen("d.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
  sort(a, a + n);
  int ans = 0, sum = 10, pnt = 0;
  for (int i = 0; i < n; i ++) {
    sum += a[i];
    if (sum <= 720) ans ++, pnt += max(0, sum - 360);
  }
  printf("%d %d\n", ans, pnt);
}