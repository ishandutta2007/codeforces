#include <bits/stdc++.h>

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  std::vector<int> b(n);
  for (int& e : b) {
    is >> e;
  }

  for (int i = 0; i < n; ++i) {
    os << *std::lower_bound(b.begin(), b.end(), a[i]) - a[i]
       << " \n"[i + 1 == n];
  }

  for (int i = 0; i < n;) {
    int j = i;
    while (j + 1 < n && a[j + 1] <= b[j]) {
      ++j;
    }

    for (int k = i; k <= j; ++k) {
      os << b[j] - a[k] << " \n"[k + 1 == n];
    }

    i = j + 1;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve(std::cin, std::cout);
  }
}