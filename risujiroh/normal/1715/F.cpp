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
  os << std::fixed << std::setprecision(15);

  int n[2];
  is >> n[0] >> n[1];

  using R = double;

  R const eps = 1e-10;

  double ans[2];

  for (int z : {0, 1}) {
    if (n[z] == 1) {
      ans[z] = 0;
      continue;
    }

    os << "? " << 4 * (n[z] - 1) << std::endl;
    auto f = [&](R x, R y) {
      if (z) {
        std::swap(x, y);
      }
      os << x << ' ' << y << std::endl;
    };
    for (int i = 1; i < n[z]; ++i) {
      f((i + 1) - R(i) / n[z], i == 1 ? -1 : 0);
      f((i + 1) - R(i) / n[z], n[z ^ 1]);
      f((i + 1), n[z ^ 1]);
      f((i + 1), i + 1 == n[z] ? -1 : 0);
    }

    R area;
    is >> area;

    for (int i = 0; i < n[z]; ++i) {
      if (area < R(i) / n[z] + eps) {
        R l = R(n[z] - 1) / n[z] * i;
        os << "? 4" << std::endl;
        f(l + 1, 0);
        f(l + 1, n[z ^ 1]);
        f(l + 2, n[z ^ 1]);
        f(l + 2, 0);

        R t;
        is >> t;

        ans[z] = l + t;
        break;
      }
    }
  }

  os << "! " << ans[0] << ' ' << ans[1] << std::endl;
}