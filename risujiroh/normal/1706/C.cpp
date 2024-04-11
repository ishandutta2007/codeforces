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

  std::vector<int> h(n);
  for (int& e : h) {
    is >> e;
  }

  using i64 = long long;

  std::vector<i64> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    if (1 <= i && i < n - 1 && i & 1) {
      cur = std::max((std::max(h[i - 1], h[i + 1]) + 1) - h[i], 0);
    }

    pref[i + 1] = pref[i] + cur;
  }

  std::vector<i64> suff(n + 1);
  for (int i = n; i--;) {
    int cur = 0;
    if (1 <= i && i < n - 1 && ~i & 1) {
      cur = std::max((std::max(h[i - 1], h[i + 1]) + 1) - h[i], 0);
    }

    suff[i] = cur + suff[i + 1];
  }

  if (n & 1) {
    os << pref[n] << '\n';
  } else {
    i64 ans = pref[n];
    for (int i = 0; i <= n; ++i) {
      ans = std::min(ans, pref[i] + suff[i]);
    }
    os << ans << '\n';
  }
}