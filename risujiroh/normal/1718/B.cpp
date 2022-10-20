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
  static auto f = [] {
    std::vector<int> ret{1, 2};
    while (true) {
      if (int t = ret.end()[-2] + ret.back(); t <= 1e9) {
        ret.push_back(t);
      } else {
        break;
      }
    }
    return ret;
  }();

  int n;
  is >> n;

  std::vector<int> c(n);
  for (int& e : c) {
    is >> e;
  }

  std::vector<std::bitset<64>> bs(n);

  for (int i = 0; i < n; ++i) {
    int t = c[i];
    for (int j = int(f.size()); j--;) {
      if (f[j] <= t) {
        t -= f[j];
        bs[i][j] = 1;
      }
    }
  }

  for (int x = 0; x < n; ++x) {
    --c[x];

    std::bitset<64> cur;
    bool ok = true;
    {
      int t = c[x];
      for (int j = int(f.size()); j--;) {
        if (f[j] <= t) {
          t -= f[j];
          cur[j] = 1;
        }
      }
    }
    if (cur[0]) {
      ok = false;
    }
    for (int i = 0; i < n; ++i) {
      if (i != x) {
        if ((cur & bs[i]).any()) {
          ok = false;
          break;
        }
        cur |= bs[i];
      }
    }
    for (int j = 1; j < 43; ++j) {
      if (cur[j - 1] == 0 && cur[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      os << "YES\n";
      return;
    }

    ++c[x];
  }
  os << "NO\n";
}