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
  if (accumulate(begin(a), end(a), 0) < 2 * (n - 1)) return cout << "NO" << '\n', 0;
  V<> vs;
  for (int i = 0; i < n; ++i) if (a[i] >= 2) vs.push_back(i);
  V< pair<int, int> > res;
  int k = vs.size();
  for (int i = 0; i < k - 1; ++i) res.emplace_back(vs[i], vs[i + 1]), --a[vs[i]], --a[vs[i + 1]];
  bool last = false, first = false;
  int d = k;
  for (int i = 0; i < n; ++i) if (!binary_search(begin(vs), end(vs), i)) {
    if (!last) {
      last = true;
      res.emplace_back(vs[k - 1], i), --a[vs[k - 1]];
      ++d;
    } else {
      for (int j = 0; j < k; ++j) if (a[vs[j]]) {
        res.emplace_back(vs[j], i), --a[vs[j]];
        first = true;
        break;
      }
    }
  }
  d += first;
  int m = res.size();
  cout << "YES" << ' ' << d - 1 << '\n';
  cout << m << '\n';
  for (int i = 0; i < m; ++i) cout << res[i].first + 1 << ' ' << res[i].second + 1 << '\n';
}