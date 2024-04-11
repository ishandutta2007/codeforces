#include <bits/stdc++.h>

using namespace std::literals;

void solve(std::istream& is, std::ostream& os) {
  int n, k;
  is >> n >> k;
  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }
  if (std::count(a.begin(), a.end(), 1)) {
    os << "YES\n";
  } else {
    os << "NO\n";
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