#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<vector<bool>> fl(n, vector<bool> (n, false)), fr(n, vector<bool> (n, false)), ok(n, vector<bool> (n, false));
  for (int i = 0; i < n; ++i) {
    fl[i][i] = fr[i][i] = true;
    for (int j = 0; j < n; ++j) {
      ok[i][j] = __gcd(a[i], a[j]) != 1;
    }
  }
  for (int length = 0; length < n; ++length) {
    for (int l = 0, r = length; r < n; ++l, ++r) {
      for (int root = l; root <= r; ++root) {
        if (fl[l][root] && fr[r][root]) {
          if (r + 1 < n && ok[root][r + 1]) {
            fl[l][r + 1] = true;
          }
          if (l && ok[root][l - 1]) {
            fr[r][l - 1] = true;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (fl[0][i] && fr[n - 1][i]) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}