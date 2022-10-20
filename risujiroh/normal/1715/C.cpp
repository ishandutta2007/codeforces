#include <bits/stdc++.h>

void solve(std::istream&, std::ostream&);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve(std::cin, std::cout);
}

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n, m;
  is >> n >> m;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  auto f = [&](int i) -> i64 {
    assert(0 < i && i < n);
    if (a[i - 1] == a[i]) {
      return 0;
    } else {
      return i * i64(n - i);
    }
  };

  i64 ans = n * i64(n + 1) / 2;
  for (int i = 1; i < n; ++i) {
    ans += f(i);
  }

  while (m--) {
    int i, x;
    is >> i >> x;
    --i;

    if (i) {
      ans -= f(i);
    }
    if (i + 1 < n) {
      ans -= f(i + 1);
    }

    a[i] = x;

    if (i) {
      ans += f(i);
    }
    if (i + 1 < n) {
      ans += f(i + 1);
    }

    os << ans << '\n';
  }
}