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

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> a(n);
  bool ans = true;
  for (int i = 0; i < n; ++i) {
    is >> a[i];

    ans &= a[i] % a[0] == 0;
  }

  os << (ans ? "Yes\n" : "No\n");
}