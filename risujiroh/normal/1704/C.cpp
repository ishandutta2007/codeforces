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
  int n, m;
  is >> n >> m;

  std::vector<int> a(m);
  for (int& e : a) {
    is >> e;
  }

  std::sort(a.begin(), a.end());
  a.push_back(a[0] + n);

  std::vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    b[i] = a[i + 1] - a[i] - 1;
  }
  std::sort(b.begin(), b.end(), std::greater());

  int ans = n;
  {
    int i = 0;
    for (int e : b) {
      if (e == 0) {
        continue;
      }
      if (i == (e - 1) / 2) {
        --ans;
        ++i;
      } else {
        if (2 * i + 1 < e) {
          ans -= e - (2 * i + 1);
          i += 2;
        }
      }
    }
  }
  os << ans << '\n';
}