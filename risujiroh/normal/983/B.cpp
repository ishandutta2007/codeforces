#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> qs(n + 1);
  for (int id = 0; id < q; ++id) {
    int l, r;
    cin >> l >> r;
    --l;
    qs[r].emplace_back(l, id);
  }
  vector f(n, vector(n, -1));
  for (int l = n; l--; ) {
    f[l][l] = a[l];
    for (int r = l + 1; r < n; ++r) {
      f[l][r] = f[l][r - 1] ^ f[l + 1][r];
    }
  }
  vector<int> res(q);
  vector<int> mx(n + 1);
  for (int r = 1; r <= n; ++r) {
    for (int i = r; i--; ) {
      mx[i] = max({mx[i], mx[i + 1], f[i][r - 1]});
    }
    for (auto [l, id] : qs[r]) {
      res[id] = mx[l];
    }
  }
  for (auto e : res) {
    cout << e << '\n';
  }
}