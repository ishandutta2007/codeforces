#include <bits/stdc++.h>

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

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n, l, r;
  is >> n >> l >> r;

  for (int i = 1; i <= n; ++i) {
    if (r / i * i < l) {
      os << "NO\n";
      return;
    }
  }

  os << "YES\n";
  for (int i = 1; i <= n; ++i) {
    os << r / i * i << " \n"[i == n];
  }
}