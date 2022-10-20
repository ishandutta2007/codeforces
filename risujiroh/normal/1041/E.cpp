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
  V<> a(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y, x--, y--;
    if (x > y) swap(x, y);
    if (x == n - 1 or y != n - 1) return cout << "NO" << '\n', 0;
    a[i] = x;
  }
  sort(a.begin(), a.end());
  V<> c(n - 1);
  for (int i = 0; i < n - 1; i++) c[a[i]]++;
  V<bool> used(n);
  used[n - 1] = true;
  for (int i = 0; i < n - 1; i++) if (c[i]) used[i] = true;
  int p = n - 1;
  V<> res;
  for (int i = n - 2; i >= 0; i--) if (c[i]) {
    res.push_back(n - 1);
    p = min(p, i);
    for (int _ = 0; _ < c[i] - 1; _++) {
      while (p >= 0 and used[p]) p--;
      if (p < 0) return cout << "NO" << '\n', 0;
      res.push_back(p), res.push_back(p);
      used[p] = true;
    }
    res.push_back(i);
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n - 1; i++) cout << min(res[2 * i], res[2 * i + 1]) + 1 << ' ' << max(res[2 * i], res[2 * i + 1]) + 1 << '\n';
}