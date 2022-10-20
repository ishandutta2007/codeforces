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
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    V<> l(n), r(n), xs;
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i], l[i] <<= 1, r[i] <<= 1, --l[i];
      xs.push_back(l[i]);
      xs.push_back(r[i]);
    }
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    for (int i = 0; i < n; ++i) {
      l[i] = distance(begin(xs), lower_bound(begin(xs), end(xs), l[i]));
      r[i] = distance(begin(xs), lower_bound(begin(xs), end(xs), r[i]));
    }
    V<> a(xs.size());
    for (int i = 0; i < n; ++i) {
      ++a[l[i]];
      --a[r[i]];
    }
    for (int i = 0; i + 1 < xs.size(); ++i) {
      a[i + 1] += a[i];
    }
    if (count(begin(a), --end(a), 0) > 0) {
      int j = find(begin(a), end(a), 0) - begin(a);
      for (int i = 0; i < n; ++i) {
        if (l[i] > j) cout << 1;
        else cout << 2;
        cout << (i != n - 1 ? ' ' : '\n');
      }
    } else {
      cout << -1 << '\n';
    }
  }
}