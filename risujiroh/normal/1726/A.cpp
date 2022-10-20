#include <bits/stdc++.h>

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  if (n == 1) {
    os << "0\n";
    return;
  }

  int ans = a.back() - a[0];
  for (int i = 1; i < n; ++i) {
    ans = std::max(ans, a[i] - a[0]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    ans = std::max(ans, a.back() - a[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    ans = std::max(ans, a[i] - a[i + 1]);
  }

  os << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    solve(std::cin, std::cout);
  }
}