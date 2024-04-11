#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return a[i] > a[j]; });
  V<bool> b(n);
  lint sum = 0;
  for (int i = 0; i < m * k; ++i) {
    b[idx[i]] = true;
    sum += a[idx[i]];
  }
  cout << sum << '\n';
  int t = 0;
  int j = 0;
  for (int i = 0; i < n; ++i) if (b[i]) {
    if (++t == m) {
      t = 0;
      ++j;
      cout << i + 1 << " \n"[j == k - 1];
      if (j == k - 1) break;
    }
  }
}