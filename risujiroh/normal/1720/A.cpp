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

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  i64 a, b, c, d;
  is >> a >> b >> c >> d;

  if (a * d == b * c) {
    os << "0\n";
  } else if ((b * c && (a * d) % (b * c) == 0) ||
             (a * d && (b * c) % (a * d) == 0)) {
    os << "1\n";
  } else {
    os << "2\n";
  }
}