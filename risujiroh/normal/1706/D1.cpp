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

  std::priority_queue<std::pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    q.emplace(a[i], i);
  }

  int min = a[0];
  int ans = a.back() - min;

  while (true) {
    auto [qi, i] = q.top();
    q.pop();

    ans = std::min(ans, qi - min);

    if (qi == 0) {
      break;
    }

    int l = a[i] / qi + 1;
    if (m < l) {
      break;
    }

    qi = a[i] / l;
    min = std::min(min, qi);
    q.emplace(qi, i);
  }

  os << ans << '\n';
}