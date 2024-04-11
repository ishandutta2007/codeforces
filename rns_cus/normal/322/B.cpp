#include <bits/stdc++.h>
using namespace std;

int a[5];

int main() {
  for (int i = 0; i < 3; i ++) scanf("%d", &a[i]);
  sort(a, a + 3);
  int ans = 0;
  for (int k = 0; k <= min(a[0], 2); k ++) {
    ans = max(ans, k + (a[0] - k) / 3 + (a[1] - k) / 3 + (a[2] - k) / 3);
  }
  printf("%d\n", ans);
}