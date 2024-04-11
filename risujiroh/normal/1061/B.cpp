#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  lint s = accumulate(begin(a), end(a), 0LL);
  sort(begin(a), end(a));
  int t = 0;
  for (int i = 0; i < n; ++i) if (a[i] > t) ++t;
  cout << s - (n + *max_element(begin(a), end(a)) - t) << '\n';
}