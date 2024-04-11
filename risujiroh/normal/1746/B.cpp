#include <bits/stdc++.h>

using namespace std::literals;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;
  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }
  int z = int(std::count(a.begin(), a.end(), 0));
  os << std::count(a.begin(), a.begin() + z, 1) << '\n';
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