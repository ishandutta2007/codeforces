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
  V<lint> l(n), r(n); for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  lint res = 0;
  for (int i = 0; i < n; i++) res += max(l[i], r[i]) + 1;
  cout << res << '\n';
}