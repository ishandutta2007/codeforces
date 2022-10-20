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
  int n, q;
  is >> n >> q;

  std::vector<std::array<int, 3>> ijxs(q);
  for (auto& [i, j, x] : ijxs) {
    is >> i >> j >> x;
    --i;
    --j;
    if (j < i) {
      std::swap(i, j);
    }
  }

  std::vector<int> b(n, ~-(1 << 30));
  for (auto [i, j, x] : ijxs) {
    b[i] &= x;
    b[j] &= x;
  }

  std::vector<int> a(n);
  for (auto [i, j, x] : ijxs) {
    assert((x & ~(b[i] | b[j])) == 0);
    a[j] |= x & ~b[i];
    a[i] |= x & ~b[j];
  }

  std::sort(ijxs.begin(), ijxs.end());
  for (auto [i, j, x] : ijxs) {
    a[j] |= x & ~a[i];
  }

  for (int i = 0; i < n; ++i) {
    os << a[i] << " \n"[i + 1 == n];
  }
}