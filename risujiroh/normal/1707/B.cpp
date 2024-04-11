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
  int n;
  is >> n;

  std::vector<std::pair<int, int>> a;
  for (int _ = n; _--;) {
    int x;
    is >> x;

    if (a.empty() || a.back().first != x) {
      a.emplace_back(x, 1);
    } else {
      ++a.back().second;
    }
  }

  for (int _ = n - 1; _--;) {
    std::vector<std::pair<int, int>> b;
    for (int i = 0; i < int(a.size()); ++i) {
      if (i) {
        b.emplace_back(a[i].first - a[i - 1].first, 1);
      }
      if (1 < a[i].second) {
        b.emplace_back(0, a[i].second - 1);
      }
    }
    std::sort(b.begin(), b.end());

    a.clear();
    for (auto [v, c] : b) {
      if (a.empty() || a.back().first != v) {
        a.emplace_back(v, c);
      } else {
        a.back().second += c;
      }
    }
  }
  os << a[0].first << '\n';
}