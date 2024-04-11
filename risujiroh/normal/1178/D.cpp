#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

V<> sieve(int n) {
  V<bool> b((n + 1) / 3, true);
  V<> res{2, 3};
  for (int p = 5, d = 2; p * p < n; p += d, d = 6 - d) if (b[p / 3]) {
    for (int i = 5 * p, d = 2 * p; i < n; i += d, d = 6 * p - d) b[i / 3] = false;
  }
  for (int p = 5, d = 2; p < n; p += d, d = 6 - d) if(b[p / 3]) res.push_back(p);
  while (!res.empty() and res.back() >= n) res.pop_back();
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  auto ps = sieve(2 * n + 10);
  int m = *lower_bound(begin(ps), end(ps), n);
  cout << m << '\n';
  auto out = [&](int i, int j) -> void {
    cout << i % n + 1 << ' ' << j % n + 1 << '\n';
  };
  for (int i = 0; i < n; ++i) {
    out(i, i + 1);
  }
  for (int i = 0; i < m - n; ++i) {
    out(i, i + n / 2);
  }
}