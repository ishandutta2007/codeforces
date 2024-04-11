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
  int n;
  is >> n;

  std::vector<std::vector<int>> pos(n);
  for (int i = 0; i < n; ++i) {
    int c;
    is >> c;
    --c;
    pos[c].push_back(i);
  }

  for (int c = 0; c < n; ++c) {
    std::array<int, 2> f{0, 0};

    for (int i : pos[c]) {
      auto nf = f;
      i &= 1;
      nf[i] = std::max(nf[i], f[i ^ 1] + 1);
      f = nf;
    }

    os << std::max(f[0], f[1]) << " \n"[c + 1 == n];
  }
}