#include <bits/extc++.h>

template <class S>
auto rle(const S& s) {
  std::vector<std::pair<typename S::value_type, int>> res;
  for (const auto& c : s)
    if (empty(res) or res.back().first != c)
      res.emplace_back(c, 1);
    else
      ++res.back().second;
  return res;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  vector<int> res;
  res.reserve(n);
  int mx = 0;
  auto v = rle(a);
  int m = size(v);
  auto f = [&](int i) -> bool { return v[i].second == 1 and i and i != m - 1; };
  int cur = 0;
  for (int i = 0; i < m; ++i) {
    auto [val, len] = v[i];
    if (f(i)) {
      ++cur;
      if (not f(i + 1)) {
        if (cur & 1) {
          for (int _ = cur; _--;) res.push_back(val ^ 1);
        } else {
          for (int _ = cur / 2; _--;) res.push_back(val);
          for (int _ = cur / 2; _--;) res.push_back(val ^ 1);
        }
        mx = max(mx, (cur + 1) / 2);
        cur = 0;
      }
    } else {
      for (int _ = len; _--;) res.push_back(val);
    }
  }
  cout << mx << '\n';
  for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i == n - 1];
}