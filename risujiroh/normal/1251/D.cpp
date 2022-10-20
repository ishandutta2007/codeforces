#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    lint s; cin >> s;
    V<> l(n), u(n); for (int i = 0; i < n; ++i) cin >> l[i] >> u[i];
    V<> idx(n);
    iota(begin(idx), end(idx), 0);
    auto chk = [&](int mid) -> bool {
      sort(begin(idx), end(idx), [&](int i, int j) {
        return make_pair(u[i] >= mid, l[i]) < make_pair(u[j] >= mid, l[j]);
      });
      if (u[idx[(n - 1) / 2]] < mid) return false;
      lint sum = 0;
      for (int t = 0; t < (n - 1) / 2; ++t) {
        sum += l[idx[t]];
      }
      for (int t = (n - 1) / 2; t < n; ++t) {
        sum += max(l[idx[t]], mid);
      }
      return s >= sum;
    };
    int ok = 0, ng = 1e9 + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (chk(mid) ? ok : ng) = mid;
    }
    cout << ok << '\n';
  }
}