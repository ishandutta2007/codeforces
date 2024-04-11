#ifndef LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>

void solve(std::istream&, std::ostream&);

int main() {
#ifndef LOCAL
  std::cin.tie(nullptr)->sync_with_stdio(false);
#endif

  int t;
  std::cin >> t;

  for (int i = 1; i <= t; ++i) {
    solve(std::cin, std::cout);
  }
}

void solve(std::istream& is, std::ostream& os) {
  int n, m;
  is >> n >> m;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  std::vector<std::vector<int>> v(a.back() + 1);
  for (int i = 0; i < n; ++i) {
    v[a[i]].push_back(i);
  }

  int min = a[0];
  int ans = a.back() - min;

  [&] {
    for (int q = int(v.size()); q--;) {
      while (!v[q].empty()) {
        int i = v[q].back();
        v[q].pop_back();

        ans = std::min(ans, q - min);

        if (q == 0) {
          return;
        }

        int l = a[i] / q + 1;
        if (m < l) {
          return;
        }

        int nq = a[i] / l;
        min = std::min(min, nq);
        v[nq].push_back(i);
      }
      std::vector<int>().swap(v[q]);
    }
  }();

  os << ans << '\n';
}