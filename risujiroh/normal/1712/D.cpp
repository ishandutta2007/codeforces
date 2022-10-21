#include <bits/extc++.h>

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
  int n, k;
  is >> n >> k;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  auto check = [&](int x) -> bool {
    int x2 = -~x >> 1;
    int c = 0;
    auto b = a;
    for (int i = 0; i < n; ++i) {
      if (b[i] < x2) {
        b[i] = x;
        ++c;
      }
    }

    if (k < c) {
      return false;
    }

    for (int i = 0; i + 1 < n; ++i) {
      if (x <= std::min(b[i], b[i + 1])) {
        return true;
      }
    }

    if (k == c) {
      return false;
    }

    if (c + 2 <= k) {
      return true;
    }

    for (int i = 0; i < n; ++i) {
      if (x <= b[i]) {
        return true;
      }
    }
    return false;
  };

  int ok = 1;
  int ng = int(1e9) + 1;
  while (ok + 1 < ng) {
    int mid = (ok + ng) >> 1;
    (check(mid) ? ok : ng) = mid;
  }
  os << ok << '\n';
}