#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> c(n * k);
  for (auto&& e : c) {
    cin >> e;
    --e;
  }
  vector<pair<int, int>> ans(n, {-1, -1});
  for (int l = 0; l < n; l += k - 1) {
    int r = min(l + k - 1, n);
    vector<int> pos(r - l, -1);
    for (int i = 0; i < n * k; ++i) {
      if (!(l <= c[i] && c[i] < r)) continue;
      if (ans[c[i]].first != -1) continue;
      if (pos[c[i] - l] != -1) {
        ans[c[i]] = {pos[c[i] - l], i};
        fill(begin(pos), end(pos), -1);
      } else {
        pos[c[i] - l] = i;
      }
    }
  }
  for (auto&& [a, b] : ans) cout << a + 1 << ' ' << b + 1 << '\n';
}