#ifndef LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>

void solve(std::istream&, std::ostream&);

int main() {
#ifndef LOCAL
  std::cin.tie(nullptr)->sync_with_stdio(false);
#endif

  int t;
  std::cin >> t;

  for (int i = 1; i <= t; ++i) {
    solve(std::cin, std::cout);
  }
}

void solve(std::istream& is, std::ostream& os) {
  int n, m;
  is >> n >> m;

  std::string ans(m, 'B');

  while (n--) {
    int a;
    is >> a;
    --a;
    int b = m - a - 1;
    if (b < a) {
      std::swap(a, b);
    }
    if (ans[a] == 'B') {
      ans[a] = 'A';
    } else if (ans[b] == 'B') {
      ans[b] = 'A';
    }
  }

  os << ans << '\n';
}