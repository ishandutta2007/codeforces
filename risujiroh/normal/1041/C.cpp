#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m, d; cin >> n >> m >> d, d++;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<> c = a;
  sort(a.begin(), a.end());
  int mx = -1;
  for (int i = 0; i < n; i++) mx = max(mx, lower_bound(a.begin(), a.end(), a[i] + d) - (a.begin() + i));
  cout << mx << '\n';
  V<> res(n);
  for (int i = 0; i < n; i++) res[i] = (lower_bound(a.begin(), a.end(), c[i]) - a.begin()) % mx;
  for (int i = 0; i < n; i++) cout << res[i] + 1 << (i != n - 1 ? ' ' : '\n');
}