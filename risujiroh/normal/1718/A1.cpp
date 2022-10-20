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

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> a(n);
  for (int& e : a) {
    is >> e;
  }

  std::vector<int> s(n + 1);
  for (int i = n; i--;) {
    s[i] = a[i] ^ s[i + 1];
  }

  std::vector<int> f(n + 1, n + 1);
  f[n] = 0;
  std::map<int, int> map;
  map[s[n]] = n;
  for (int i = n; i--;) {
    // f[i] = (a[i] != 0) + f[i + 1];
    f[i] = f[i + 1] + 1;
    if (map.count(s[i])) {
      int j = map[s[i]];
      f[i] = std::min(f[i], (j - i - 1) + f[j]);
    }
    map[s[i]] = i;
  }

  os << f[0] << '\n';
}