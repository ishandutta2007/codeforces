#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto&& e : a) cin >> e, --e;
  vector f(n + 1, numeric_limits<int64_t>::max() / 2);
  f[n] = 0;
  vector<int> cnt(n);
  int tl = 0, tr = 0;
  int64_t t = 0;
  auto cost = [&](int l, int r) -> int64_t {
    while (tl > l) t += cnt[a[--tl]]++;
    while (tr < r) t += cnt[a[tr++]]++;
    while (tl < l) t -= --cnt[a[tl++]];
    while (tr > r) t -= --cnt[a[--tr]];
    return t;
  };
  while (k--) {
    auto nf = f;
    auto rec = [&](auto self, int l, int r, int lj, int rj) -> void {
      if (l > r) return;
      int m = (l + r) / 2;
      int mj = m;
      for (int j = max(m + 1, lj); j <= rj; ++j)
        if (cost(m, j) + f[j] < nf[m]) {
          nf[m] = cost(m, j) + f[j];
          mj = j;
        }
      self(self, l, m - 1, lj, mj);
      self(self, m + 1, r, mj, rj);
    };
    rec(rec, 0, n, 1, n);
    f = move(nf);
  }
  cout << f[0] << '\n';
}