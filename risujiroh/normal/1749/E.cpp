#include <bits/stdc++.h>

using namespace std::literals;

void solve(std::istream& is, std::ostream& os) {
  int n, m;
  is >> n >> m;
  std::vector<std::string> s(n);
  for (std::string& e : s) {
    is >> e;
  }
  auto is_good = [&](int i, int j) -> bool {
    static std::array<std::array<int, 2>, 4> const d4{1, 0, 0, 1, -1, 0, 0, -1};
    for (auto [ni, nj] : d4) {
      ni += i;
      nj += j;
      if (0 <= ni && ni < n && 0 <= nj && nj < m && s[ni][nj] == '#') {
        return false;
      }
    }
    return true;
  };
  std::vector d(n, std::vector<int>(m, std::numeric_limits<int>::max()));
  std::vector p(n, std::vector<std::array<int, 2>>(m, {-1, -1}));
  std::priority_queue q{std::greater{},
                        std::vector<std::pair<int, std::array<int, 2>>>{}};
  for (int i = 0; i < n; ++i) {
    if (is_good(i, 0)) {
      q.emplace(d[i][0] = s[i][0] == '.', std::array{i, 0});
    }
  }
  std::array<std::array<int, 2>, 4> const d4{1, 1, -1, 1, -1, -1, 1, -1};
  while (!q.empty()) {
    auto [dij, ij] = q.top();
    auto [i, j] = ij;
    q.pop();
    if (dij != d[i][j]) {
      continue;
    }
    if (j + 1 == m) {
      os << "YES\n";
      while (true) {
        s[i][j] = '#';
        if (j == 0) {
          break;
        }
        auto [ni, nj] = p[i][j];
        i = ni;
        j = nj;
      }
      for (std::string& e : s) {
        os << e << '\n';
      }
      return;
    }
    for (auto [ni, nj] : d4) {
      ni += i;
      nj += j;
      if (ni < 0 || n <= ni || nj < 0 || m <= nj || !is_good(ni, nj)) {
        continue;
      }
      if (int t = dij + (s[ni][nj] == '.'); t < d[ni][nj]) {
        q.emplace(d[ni][nj] = t, std::array{ni, nj});
        p[ni][nj] = {i, j};
      }
    }
  }
  os << "NO\n";
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