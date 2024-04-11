#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, q; cin >> n >> q;
  for (int i = 0; i < q; i++) {
    lint x, y; cin >> x >> y;
    if (x + y & 1) {
      cout << ((x + n - 1) * n + y + 1) / 2 << '\n';
    } else {
      cout << ((x - 1) * n + y + 1) / 2 << '\n';
    }
  }
}