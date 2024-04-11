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
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    a[i] = n - a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    ++mp[a[i]];
  }
  for (const auto& e : mp) {
    if (e.second % e.first) {
      return cout << "Impossible" << '\n', 0;
    }
  }
  cout << "Possible" << '\n';
  VV<> id(n + 1);
  for (int i = 0; i < n; ++i) {
    id[a[i]].push_back(i);
  }
  V<> b(n);
  int t = 1;
  for (int x = 1; x <= n; ++x) {
    int m = id[x].size();
    assert(m % x == 0);
    for (int i = 0; i < m / x; ++i) {
      for (int j = 0; j < x; ++j) b[id[x][i * x + j]] = t;
      ++t;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << (i != n - 1 ? ' ' : '\n');
  }
}