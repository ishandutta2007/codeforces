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
  if (n == 1) return cout << "Yes" << '\n', 0;
  VV<> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y, x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  V<> p(n, -1);
  queue<int> q;
  p[0] = -2; q.push(0);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int i : g[v]) if (p[i] == -1) {
      p[i] = v; q.push(i);
    }
  }
  VV<> c(n);
  for (int i = 1; i < n; i++) c[p[i]].push_back(i);
  for (auto&& v : c) sort(v.begin(), v.end());

  if (a[0] != 0) return cout << "No" << '\n', 0;
  q.push(0);
  int t = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    V<> d;
    for (int i = 0; i < c[v].size(); i++) d.push_back(a[t++]);
    for (int i : d) q.push(i);
    sort(d.begin(), d.end());
    if (c[v] != d) return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
}