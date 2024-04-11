#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, M; cin >> n >> M;
  V<> t(n); for (auto&& e : t) cin >> e;
  V<> c(101);
  for (int i = 0; i < n; ++i) {
    int res = i, s = M - t[i];
    for (int x = 1; x <= 100; ++x) {
      int k = min(s / x, c[x]);
      s -= k * x;
      res -= k;
    }
    cout << res << " \n"[!(n + ~i)];
    ++c[t[i]];
  }
}