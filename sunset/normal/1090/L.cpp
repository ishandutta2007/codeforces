#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int t, n, a, b, k;
  scanf("%d %d %d %d %d", &t, &n, &a, &b, &k);
  int l = 0, r = t;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if ((long long)mid * k <= (long long)min(mid, a) * (n + 1 >> 1) + (long long)min(mid, b) * (n >> 1)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%d\n", l);
  return 0;
}