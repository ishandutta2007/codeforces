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
  int n, x;
  is >> n >> x;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  int ans = 0;
  for (int l = 0; l < n;) {
    int min = a[l];
    int max = a[l];
    int i = l;
    while (i + 1 < n &&
           std::max(max, a[i + 1]) - std::min(min, a[i + 1]) <= 2 * x) {
      ++i;
      min = std::min(min, a[i]);
      max = std::max(max, a[i]);
    }
    ++ans;
    l = i + 1;
  }
  --ans;
  os << ans << '\n';
}