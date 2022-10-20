#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    V<lint> v(3); for (auto&& e : v) cin >> e;
    sort(begin(v), end(v));
    lint res = 0;
    do {
      lint a = v[0], b = v[1], c = v[2];
      if (a > b) swap(a, b);
      res = max(res, b - a <= c ? a + b + c >> 1 : a + c);
    } while (next_permutation(begin(v), end(v)));
    cout << res << '\n';
  }
}