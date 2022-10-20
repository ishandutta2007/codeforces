#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  int m; cin >> m;
  V<> b(m); for (int i = 0; i < m; i++) cin >> b[i];
  V<lint> ca(n + 1); for (int i = 0; i < n; i++) ca[i + 1] = ca[i] + a[i];
  V<lint> cb(m + 1); for (int i = 0; i < m; i++) cb[i + 1] = cb[i] + b[i];
  if (ca[n] != cb[m]) return cout << -1 << '\n', 0;
  V<lint> c;
  merge(ca.begin(), ca.end(), cb.begin(), cb.end(), back_inserter(c));
  c.erase(unique(c.begin(), c.end()), c.end());
  cout << n + m - c.size() + 1 << '\n';
}