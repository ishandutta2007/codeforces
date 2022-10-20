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
  int n, q;
  is >> n >> q;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  std::reverse(a.begin(), a.end());

  std::string ans(n, '0');

  int cur = 1;
  for (int l = 0; l < n;) {
    ans[l] = '1';
    int r = l + 1;
    while (r < n && a[r] <= cur) {
      ans[r] = '1';
      ++r;
    }
    l = r;

    ++cur;
    if (q < cur) {
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] <= q) {
      ans[i] = '1';
    }
  }

  std::reverse(ans.begin(), ans.end());
  os << ans << '\n';
}