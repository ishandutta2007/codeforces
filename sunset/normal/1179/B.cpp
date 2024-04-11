#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1, j = n; i < j; ++i, --j) {
    for (int k = 1, l = m; k <= m; ++k, --l) {
      cout << i << " " << k << "\n";
      cout << j << " " << l << "\n";
    }
  }
  if (n & 1) {
    for (int i = 1, j = m; i <= j; ++i, --j) {
      cout << (n + 1) / 2 << " " << i << "\n";
      if (i != j) {
        cout << (n + 1) / 2 << " " << j << "\n";
      }
    }
  }
  return 0;
}