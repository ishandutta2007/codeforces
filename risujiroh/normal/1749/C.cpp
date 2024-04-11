#include <bits/stdc++.h>

using namespace std::literals;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;
  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }
  for (int k = n;; --k) {
    if ([&] {
          std::multiset b(a.begin(), a.end());
          for (int i = 0; i < k; ++i) {
            auto it = b.upper_bound(k - i);
            if (it == b.begin()) {
              return false;
            }
            --it;
            b.erase(it);
            if (!b.empty()) {
              it = b.begin();
              b.insert(*it + (k - i));
              b.erase(it);
            }
          }
          return true;
        }()) {
      os << k << '\n';
      break;
    }
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