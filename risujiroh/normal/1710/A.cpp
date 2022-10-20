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
  int n, m, k;
  is >> n >> m >> k;

  std::vector<int> a(k);
  for (int& e : a) {
    is >> e;
  }

  for (int _ = 2; _--;) {
    i64 s = 0;
    bool any = false;
    for (int e : a) {
      int t = e / n;
      if (2 <= t) {
        s += t;
      }
      any |= 3 <= t;
    }

    if (m <= s && (~m & 1 || any)) {
      os << "Yes\n";
      return;
    }

    std::swap(n, m);
  }

  os << "No\n";
}