#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  if (m % n) return cout << -1 << '\n', 0;
  auto mp = factorize(m / n);
  int res = 0;
  for (const auto& e : mp) {
    if (e.first > 3) return cout << -1 << '\n', 0;
    res += e.second;
  }
  cout << res << '\n';
}