#include <bits/extc++.h>

void solve(std::istream&, std::ostream&);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve(std::cin, std::cout);
  }
}

using namespace std::literals;

using i64 = long long;

int const L = 2e5;

void solve(std::istream& is, std::ostream& os) {
  static auto d = [&] {
    std::vector<std::vector<int>> ret(L + 1);
    for (int i = 1; i <= L; ++i) {
      for (int j = i; j <= L; j += i) {
        ret[j].push_back(i);
      }
    }
    return ret;
  }();

  int l, r;
  is >> l >> r;

  i64 ans = i64(r - l + 1) * (r - l) * (r - l - 1) / 6;

  for (int k = l; k <= r; ++k) {
    i64 c = int(d[k].end() - std::lower_bound(d[k].begin(), d[k].end(), l)) - 1;
    ans -= c * (c - 1) / 2;

    if (k % 6 == 0) {
      ans -= l <= k / 2;
    }
    if (k % 15 == 0) {
      ans -= l <= k / 5 * 2;
    }
  }

  os << ans << '\n';
}