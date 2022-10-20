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

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> ans(n);
  std::iota(ans.begin(), ans.end(), 1);
  for (int i = int(ans.size()); 0 <= (i -= 2);) {
    std::swap(ans[i], ans[i + 1]);
  }

  for (int i = 0; i < n; ++i) {
    os << ans[i] << " \n"[i + 1 == n];
  }
}