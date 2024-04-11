#include <bits/stdc++.h>

void solve(std::istream& is, std::ostream& os) {
  std::set<char> s;
  for (int _ = 4; _--;) {
    char c;
    is >> c;
    s.insert(c);
  }
  os << s.size() - 1 << '\n';
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