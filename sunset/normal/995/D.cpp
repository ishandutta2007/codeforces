#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(1 << n);
  ll sum = 0;
  for (int i = 0; i < 1 << n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  printf("%lf\n", (double)sum / (1 << n));
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    sum -= a[x];
    a[x] = y;
    sum += a[x];
    printf("%lf\n", (double)sum / (1 << n));
  }
  return 0;
}