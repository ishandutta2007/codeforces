#include <bits/stdc++.h>

using namespace std::literals;

using ll = long long;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;
  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }
  std::vector<int> b(n);
  for (int& e : b) {
    is >> e;
  }
  ll ans = std::accumulate(a.begin(), a.end(), 0ll);
  ans += std::accumulate(b.begin(), b.end(), 0ll);
  ans -= *std::max_element(b.begin(), b.end());
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