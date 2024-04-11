#include <bits/stdc++.h>

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> ans(n);
  std::iota(ans.begin(), ans.end(), 1);
  if (n & 1) {
    for (int i = 3; i < n - 2; i += 2) {
      std::swap(ans[i], ans[i + 1]);
    }
  } else {
    for (int i = 0; i < n - 2; i += 2) {
      std::swap(ans[i], ans[i + 1]);
    }
  }

  for (int i = 0; i < n; ++i) {
    os << ans[i] << " \n"[i + 1 == n];
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