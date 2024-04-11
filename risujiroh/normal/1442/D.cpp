#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  constexpr auto inf = numeric_limits<int64_t>::max() / 2;

  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  vector<vector<int>> a(n);
  vector<int64_t> sum(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    a[i].resize(t[i]);
    for (auto&& e : a[i]) {
      cin >> e;
      sum[i] += e;
    }
  }

  auto add = [&](const auto& v, int i) {
    auto res = v;
    for (int x = 0; x + t[i] <= k; ++x)
      res[x + t[i]] = max(res[x + t[i]], v[x] + sum[i]);
    return res;
  };

  auto ans = -inf;
  auto rec = [&](auto self, int l, int r, const auto& v) -> void {
    if (r - l == 1) {
      int64_t cur = 0;
      for (int j = 1; j <= min(t[l], k); ++j) {
        cur += a[l][j - 1];
        ans = max(ans, cur + v[k - j]);
      }
      return;
    }
    int m = (l + r) / 2;
    {
      auto nv = v;
      for (int i = m; i < r; ++i) nv = add(nv, i);
      self(self, l, m, nv);
    }
    {
      auto nv = v;
      for (int i = l; i < m; ++i) nv = add(nv, i);
      self(self, m, r, nv);
    }
  };

  vector v(k + 1, -inf);
  v[0] = 0;
  rec(rec, 0, n, v);
  cout << ans << '\n';
}