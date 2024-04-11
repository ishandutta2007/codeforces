#include <bits/stdc++.h>

void solve(std::istream& is, std::ostream& os) {
  int n, m, sx, sy, d;
  is >> n >> m >> sx >> sy >> d;
  --sx;
  --sy;

  auto f = [&](int i, int j) {
    return std::abs(i - sx) + std::abs(j - sy) <= d;
  };

  bool ans = [&] {
    for (int i = 1; i < n; ++i) {
      if (f(i, 0)) {
        return false;
      }
    }
    for (int j = 1; j < m; ++j) {
      if (f(n - 1, j)) {
        return false;
      }
    }
    return true;
  }();

  ans |= [&] {
    for (int j = 1; j < m; ++j) {
      if (f(0, j)) {
        return false;
      }
    }
    for (int i = 1; i < n; ++i) {
      if (f(i, m - 1)) {
        return false;
      }
    }
    return true;
  }();

  os << (ans ? n + m - 2 : -1) << '\n';
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