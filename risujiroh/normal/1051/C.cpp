#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr int MX = 100;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<> c(MX + 1);
  for (int i = 0; i < n; i++) c[a[i]]++;
  V<> d(n + 1);
  for (int i = 0; i < MX + 1; i++) if (c[i]) d[c[i]]++;
  int m = accumulate(d.begin() + 3, d.end(), 0);
  if (d[1] & 1 and !m) cout << "NO" << '\n';
  else {
    cout << "YES" << '\n';
    VV<> is(MX + 1);
    for (int i = 0; i < n; i++) is[a[i]].push_back(i);
    V<char> res(n);
    int t = 0;
    bool o = d[1] & 1;
    for (int i = 0; i < MX + 1; i++) if (c[i] == 1) {
      res[is[i][0]] = 'A' + t;
      t = 1 - t;
    } else if (c[i] == 2) {
      for (int j : is[i]) res[j] = 'A';
    } else if (c[i] >= 3) {
      if (o) {
        res[is[i][0]] = 'B';
        for (int j = 1; j < is[i].size(); j++) res[is[i][j]] = 'A';
        o = false;
      } else {
        for (int j : is[i]) res[j] = 'A';
      }
    }
    for (int i = 0; i < n; i++) cout << res[i];
    cout << '\n';
  }
}