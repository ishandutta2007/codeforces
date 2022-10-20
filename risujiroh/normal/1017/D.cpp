#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  V<> w(n); for (int i = 0; i < n; i++) cin >> w[i];
  V<> a(1 << n);
  for (int i = 0; i < m; i++) {
    string s; cin >> s;
    a[stoi(s, nullptr, 2)]++;
  }
  VV<> v; assign(v, 1 << n, 1 << n);
  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      for (int k = 0; k < n; k++) {
        v[i][j] += ((i & 1 << k) == (j & 1 << k)) * w[n - 1 - k];
      }
    }
  }
  VV<> res; assign(res, 1 << n, 101);
  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      if (v[i][j] > 100) continue;
      res[i][v[i][j]] += a[j];
    }
  }
  for (int i = 0; i < 1 << n; i++) {
    for (int j = 0; j < 100; j++) res[i][j + 1] += res[i][j];
  }
  for (int i = 0; i < q; i++) {
    string t; cin >> t;
    int k; cin >> k;
    cout << res[stoi(t, nullptr, 2)][k] << '\n';
  }
}