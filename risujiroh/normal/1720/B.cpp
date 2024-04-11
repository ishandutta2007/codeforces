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
  int n;
  is >> n;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  std::sort(a.begin(), a.end());

  os << a.back() + a.end()[-2] - a[0] - a[1] << '\n';
}