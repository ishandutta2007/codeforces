#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(n, vector<int64_t>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 and j == 0) continue;
      if (i == n - 1 and j == n - 1) continue;
      if (j & 1) a[i][j] = 1LL << (2 * n - i - j - 3);
    }
    for (int j = 0; j < n; ++j) {
      if (j) cout << ' ';
      cout << a[i][j];
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    int64_t k;
    cin >> k;
    vector<pair<int, int>> res{{0, 0}};
    int i = 0, j = 0;
    for (int s = 1; s <= 2 * n - 3; ++s) {
      auto cur = 1LL << (2 * n - s - 3);
      if (k >= cur) {
        k -= cur;
        if (j & 1)
          ++i;
        else
          ++j;
      } else {
        if (j & 1)
          ++j;
        else
          ++i;
      }
      res.emplace_back(i, j);
    }
    res.emplace_back(n - 1, n - 1);
    for (auto [i, j] : res) {
      cout << i + 1 << ' ' << j + 1 << endl;
    }
  }
}