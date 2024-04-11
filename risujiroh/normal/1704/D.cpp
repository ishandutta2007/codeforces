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
  int n, m;
  is >> n >> m;

  std::vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      i64 c;
      is >> c;

      a[i] += c * j;
    }
  }

  os << std::max_element(a.begin(), a.end()) - a.begin() + 1 << ' ';
  os << *std::max_element(a.begin(), a.end()) -
            *std::min_element(a.begin(), a.end())
     << '\n';
}