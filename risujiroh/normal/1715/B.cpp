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
  i64 n, k, b, s;
  is >> n >> k >> b >> s;

  if (s < k * b || k * b + (k - 1) * n < s) {
    os << "-1\n";
    return;
  }

  i64 rest = s - k * b;
  for (int i = 0; i < n; ++i) {
    i64 ans = i ? 0 : k * b;
    i64 t = std::min(rest, k - 1);
    ans += t;
    rest -= t;

    os << ans << " \n"[i + 1 == n];
  }
}