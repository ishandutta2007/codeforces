#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    string s, t, p; cin >> s >> t >> p;
    int m = t.size();
    int i = 0;
    bool ok = true;
    V<bool> b(m);
    for (char c : s) {
      while (i < m and t[i] != c) ++i;
      if (i == m) ok = false;
      else b[i++] = true;
    }
    sort(begin(p), end(p));
    string q;
    for (int i = 0; i < m; ++i) if (!b[i]) {
      q += t[i];
    }
    sort(begin(q), end(q));
    if (!includes(begin(p), end(p), begin(q), end(q))) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}