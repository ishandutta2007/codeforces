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
  V<lint> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<lint> b(n); for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  lint res = 0;
  for (int i = 0; i < n; i++) {
    if (b.empty() or !a.empty() and a.back() > b.back()) {
      res += a.back();
      a.pop_back();
    } else {
      b.pop_back();
    }
    if (a.empty() or !b.empty() and b.back() > a.back()) {
      res -= b.back();
      b.pop_back();
    } else {
      a.pop_back();
    }
  }
  cout << res << '\n';
}