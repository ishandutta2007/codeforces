#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> p(n, -1);
  vector<bool> ban(n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
    ban[p[i]] = true;
  }
  vector<int> a(n);
  for (int i = n - 1; ~i; --i) {
    if (!ban[i]) {
      a[i] = 1;
    }
    if (i) {
      a[p[i]] += a[i];
    }
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}