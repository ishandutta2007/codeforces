#include <bits/stdc++.h>

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n, m;
  is >> n >> m;

  if (m < n) {
    os << "No\n";
    return;
  }

  if (n & 1) {
    os << "Yes\n";
    for (int i = 0; i < n; ++i) {
      os << (i ? 1 : m - n + 1) << " \n"[i + 1 == n];
    }
  } else {
    if (m & 1) {
      os << "No\n";
    } else {
      os << "Yes\n";
      for (int i = 0; i < n; ++i) {
        os << (i < 2 ? (m - n) / 2 + 1 : 1) << " \n"[i + 1 == n];
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    solve(std::cin, std::cout);
  }
}