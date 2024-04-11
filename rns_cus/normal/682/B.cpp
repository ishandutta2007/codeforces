#include <bits/stdc++.h>
using namespace std;
int n, a[100010], dif[100010];

bool check(int x) {
  int t = lower_bound(a, a + n, x) - a;
  int tp = n - t;
  if (t) tp += dif[t - 1];
  return (x <= tp);
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  dif[0] = 1;
  for (int i = 1; i < n; i++) {
    dif[i] = dif[i - 1] + (dif[i - 1] < a[i]);
  }
  
  int l = 0, r = a[n - 1] + 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  printf("%d\n", l + 1);
}