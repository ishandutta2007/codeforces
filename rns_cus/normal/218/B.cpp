#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, m, a[N];
priority_queue <int> pq;

int main() {
 // freopen("b.in", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i ++) scanf("%d", &a[i]);
  sort(a + 1, a + m + 1);
  int k = n, mn = 0, mx = 0;
  for (int i = 1; i <= n; i ++) {
    if (k > a[i]) mn += a[i] * (a[i] + 1) / 2, k -= a[i];
    else {
      mn += (a[i] * 2 - k + 1) * k / 2; break;
    }
  }
  for (int i = 1; i <= m; i ++) pq.push(a[i]);
  while (1) {
    n --;
    int x = pq.top(); pq.pop();
    mx += x;
    if (x > 1) pq.push(x - 1);
    if (!n || pq.empty()) break;
  }
  printf("%d %d\n", mx, mn);
}