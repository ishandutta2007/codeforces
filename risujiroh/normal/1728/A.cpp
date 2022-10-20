#include <bits/stdc++.h>

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> cnt(n);
  for (int& e : cnt) {
    is >> e;
  }

  os << std::max_element(cnt.begin(), cnt.end()) - cnt.begin() + 1 << '\n';
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