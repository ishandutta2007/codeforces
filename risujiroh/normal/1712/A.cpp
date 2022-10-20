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
  int n, k;
  is >> n >> k;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int p;
    is >> p;
    --p;

    ans += i < k && k <= p;
  }
  os << ans << '\n';
}