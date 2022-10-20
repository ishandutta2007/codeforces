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
    V<> m(n), p(n); for (int i = 0; i < n; ++i) cin >> m[i] >> p[i];
    V<> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) { return make_pair(m[i], p[i]) < make_pair(m[j], p[j]); });
    int offset = 0;
    lint res = 0;
    priority_queue< int, V<>, greater<int> > pq;
    for (int t = n - 1; t >= 0; --t) {
      int i = idx[t];
      pq.push(p[i]);
      while (m[i] > offset + t) {
        ++offset;
        res += pq.top(); pq.pop();
      }
    }
    cout << res << '\n';
  }
}