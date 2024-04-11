#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<bool> exists(1 << k);
  while (n--) {
    int mask = 0;
    for (int i = 0; i < k; ++i) {
      int t;
      cin >> t;
      mask |= t << i;
    }
    exists[mask] = true;
  }
  n = 1 << k;
  for (int mask = 1; mask < 1 << n; ++mask) {
    vector<int> sum(k);
    bool any = false;
    for (int i = 0; i < n; ++i)
      if (mask >> i & 1 && exists[i]) {
        any = true;
        for (int j = 0; j < k; ++j) {
          if (i >> j & 1)
            --sum[j];
          else
            ++sum[j];
        }
      }
    if (any && *min_element(begin(sum), end(sum)) >= 0) {
      cout << "YES\n";
      exit(0);
    }
  }
  cout << "NO\n";
}