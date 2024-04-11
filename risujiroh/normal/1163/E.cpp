#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  for (int x = 20; ; --x) {
    V<> v, w;
    for (int e : a) if(e < 1 << x) {
      int t = e;
      for (int f : v) e = min(e, e ^ f);
      if (e) {
        v.push_back(e);
        w.push_back(t);
      }
    }
    if ((int)v.size() < x) continue;
    cout << x << '\n';
    int curr = 0;
    for (int i = 0; i < 1 << x; ++i) {
      cout << curr;
      if (i == ~(~0 << x)) return cout << '\n', 0;
      else cout << ' ';
      curr ^= w[__builtin_ctz(i + 1)];
    }
  }
}