#include <bits/stdc++.h>

using namespace std::literals;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;
  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }
  std::vector<int> ans(n);
  std::vector<int> order(n - 1);
  std::iota(order.begin(), order.end(), 0);
  std::sort(order.begin(), order.end(),
            [&](int i, int j) { return a[j] - a[j + 1] < a[i] - a[i + 1]; });
  for (int z = 0; z < n - 1; ++z) {
    ans[n - z - 1] = order[z] + 1;
  }
  ans[0] = 0;
  for (int i = 0; i < n; ++i) {
    os << ans[i] + 1 << " \n"[i + 1 == n];
  }
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