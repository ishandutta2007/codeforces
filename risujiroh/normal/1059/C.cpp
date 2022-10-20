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
  V<> res;
  int t = 1;
  while (n) {
    if (n == 3) {
      res.push_back(t);
      res.push_back(t);
      res.push_back(3 * t);
      break;
    }
    int m = (n + 1) / 2;
    for (int _ = 0; _ < m; _++) res.push_back(t);
    n -= m;
    t *= 2;
  }
  n = res.size();
  for (int i = 0; i < n; i++) cout << res[i] << (i != n - 1 ? ' ' : '\n');
}