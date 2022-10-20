#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b;
    string s; cin >> s;
    int n = s.size();
    V<> v;
    int c = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '.') {
        ++c;
        if (s[i] != s[i + 1] and c >= b) {
          v.push_back(c);
        }
      } else {
        c = 0;
      }
    }
    sort(begin(v), end(v));

    c = a < 2 * b ? lower_bound(begin(v), end(v), 2 * b) - lower_bound(begin(v), end(v), a) : 0;
    bool ok = false;
    [&] {
      for (int e : v) if (e >= a) {
        for (int d = 0; d <= e - a; ++d) {
          int nc = c - (e < 2 * b);
          nc += (a <= d and d < 2 * b);
          int f = e - a - d;
          nc += (a <= f and f < 2 * b);
          int sz = (int)v.size() - 1;
          sz += (d >= b) + (f >= b);
          if (nc == sz and ~nc & 1) {
            ok = true;
            return;
          }
        }
      }
    }();
    cout << (ok ? "YES" : "NO") << '\n';
  }
}