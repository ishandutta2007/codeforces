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

  std::string a, b;
  is >> a >> b;

  for (int i = 0; i < m; ++i) {
    if (i == 0) {
      bool any = false;
      for (int j = 0; j <= n - m; ++j) {
        any |= a[j] == b[i];
      }
      if (!any) {
        os << "NO\n";
        return;
      }
    } else {
      if (a[n - m + i] != b[i]) {
        os << "NO\n";
        return;
      }
    }
  }

  os << "YES\n";
}