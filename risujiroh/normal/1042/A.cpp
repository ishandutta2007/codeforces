#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int res2 = a[n - 1] + m;
  int b = 0;
  for (int i = 0; i < n - 1; i++) b += a[n - 1] - a[i];
  int res1;
  if (m <= b) res1 = a[n - 1];
  else {
    m -= b;
    res1 = a[n - 1] + (m + n - 1) / n;
  }
  cout << res1 << ' ' << res2 << '\n';
}