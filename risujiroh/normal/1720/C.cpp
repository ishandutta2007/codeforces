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
  int n, m;
  is >> n >> m;

  std::vector<std::string> s(n);
  for (std::string& e : s) {
    is >> e;
  }

  int ans = -[&] {
    bool any = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '0') {
          if (i && s[i - 1][j] == '0') {
            return 0;
          }
          if (j && s[i][j - 1] == '0') {
            return 0;
          }
          if (i && j && s[i - 1][j - 1] == '0') {
            return 0;
          }
          if (i && j + 1 < m && s[i - 1][j + 1] == '0') {
            return 0;
          }
          any = true;
        }
      }
    }
    return any ? 1 : 2;
  }();

  for (std::string& e : s) {
    ans += int(std::count(e.begin(), e.end(), '1'));
  }
  os << ans << '\n';
}