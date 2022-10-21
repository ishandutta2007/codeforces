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

  std::vector<int> c(n), p(n);
  for (int i = 0; i < n; ++i) {
    is >> c[i] >> p[i];
  }

  std::map<int, int> delta;
  for (int i = 0; i < n; ++i) {
    delta[c[i] - p[i]] += 1;
    delta[c[i]] -= 2;
    delta[c[i] + p[i]] += 1;
  }

  int a = 0;
  int px = -1e9;
  i64 y = 0;
  i64 m1 = std::numeric_limits<i64>::min();
  i64 m2 = std::numeric_limits<i64>::min();
  for (auto [x, d] : delta) {
    y += a * i64(x - px);

    if (m < y) {
      m1 = std::max(m1, x + (y - m));
      m2 = std::max(m2, (y - m) - x);
    }

    a += d;
    px = x;
  }

  for (int i = 0; i < n; ++i) {
    os << (m1 <= c[i] + p[i] && m2 <= p[i] - c[i]);
  }
  os << '\n';
}