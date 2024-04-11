#include <bits/stdc++.h>

using namespace std;

template <class C> constexpr int len(const C& c) { return int(c.size()); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> c(n);
  for (auto&& e : c) {
    cin >> e;
  }

  vector<int64_t> h(n + 1);
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      h[i + 1] = h[i] + c[i];
    } else {
      h[i + 1] = h[i] - c[i];
    }
  }

  constexpr auto inf = numeric_limits<int64_t>::max() / 2;

  int64_t ans = 0;
  for (int l = 0; l < n; l += 2) {
    auto mn = inf;
    for (int r = l + 1; r < n; r += 2) {
      ans += max<int64_t>(min({h[l + 1], mn, h[r]}) - max(h[l], h[r + 1]) + 1, 0);
      ans -= r - l == 1;
      mn = min(mn, h[r + 1]);
    }
  }
  cout << ans << '\n';
}