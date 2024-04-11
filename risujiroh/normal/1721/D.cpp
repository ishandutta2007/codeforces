#include <bits/stdc++.h>

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  std::vector<int> b(n);
  for (int& e : b) {
    is >> e;
  }

  auto check = [&](int mask) -> bool {
    std::vector<int> x(n);
    std::vector<int> y(n);
    for (int i = 0; i < n; ++i) {
      x[i] = a[i] & mask;
      y[i] = ~b[i] & mask;
    }
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    return x == y;
  };

  int ans = 0;
  for (int i = 30; i--;) {
    if (check(ans | 1 << i)) {
      ans |= 1 << i;
    }
  }
  os << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve(std::cin, std::cout);
  }
}