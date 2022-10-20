#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  bitset<101> a;
  a.set();
  for (int i = 0; i < n; ++i) {
    bitset<101> b;
    int r; cin >> r;
    for (int j = 0; j < r; ++j) {
      int x; cin >> x;
      b[x] = true;
    }
    a &= b;
  }
  V<> res;
  for (int i = 1; i < 100 + 1; ++i) if (a[i]) res.push_back(i);
  int m = res.size();
  for (int i = 0; i < m; ++i) cout << res[i] << (i != m - 1 ? ' ' : '\n');
}