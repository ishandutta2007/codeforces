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
  int n;
  is >> n;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  std::vector<int> v(n + 1, n);
  for (int i = 0; i < n; ++i) {
    v[a[i]] = std::min(v[a[i]], i);
  }

  int cur = (n + 1) - int(std::count(v.begin(), v.end(), n));
  int ans = cur;
  int mn = n;
  std::vector<bool> seen(n + 1);
  for (int l = n; l--;) {
    if (l + 1 < n && a[l + 1] < a[l]) {
      break;
    }

    if (!seen[a[l]]) {
      --cur;
      seen[a[l]] = true;
    }

    mn = std::min(mn, v[a[l]]);
    if (mn == l) {
      ans = std::min(ans, cur);
    }
  }
  os << ans << '\n';
}