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
  int n, k; cin >> n >> k;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  map<int, int> mp;
  for (int e : a) {
    ++mp[e];
  }
  for (const auto& e : mp) {
    if (e.second > k) {
      return cout << "NO" << '\n', 0;
    }
  }
  cout << "YES" << '\n';
  V<> id(n);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) { return a[i] < a[j]; });
  V<> res(n);
  for (int i = 0; i < n; ++i) {
    res[id[i]] = i % k;
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] + 1 << (i != n - 1 ? ' ' : '\n');
  }
}