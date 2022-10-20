#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  map< V<int8_t>, int > mp;
  for (int x = 0; x < 1 << 15; ++x) {
    V<int8_t> v(n);
    for (int i = 0; i < n; ++i) {
      int l = a[i] & ~(~0U << 15);
      v[i] = __builtin_popcount(l ^ x);
    }
    for (int i = n - 1; i >= 0; --i) {
      v[i] -= v[0];
    }
    mp[v] = x;
  }
  for (int x = 0; x < 1 << 15; ++x) {
    V<int8_t> v(n);
    for (int i = 0; i < n; ++i) {
      int u = a[i] >> 15;
      v[i] = -__builtin_popcount(u ^ x);
    }
    for (int i = n - 1; i >= 0; --i) {
      v[i] -= v[0];
    }
    if (mp.count(v)) {
      int res = x << 15 | mp[v];
      cout << res << '\n';
      set<int> se;
      for (int e : a) {
        se.insert(__builtin_popcount(e ^ res));
      }
      assert(se.size() == 1);
      return 0;
    }
  }
  cout << -1 << '\n';
}