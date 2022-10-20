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
  if (n == 1) return cout << a[0] << '\n', 0;
  sort(a.begin(), a.end());
  if (a[0] > 0) {
    cout << accumulate(a.begin(), a.end(), 0LL) - 2 * a[0] << '\n';
  } else if (a[n - 1] < 0) {
    cout << -accumulate(a.begin(), a.end(), 0LL) + 2 * a[n - 1] << '\n';
  } else {
    cout << accumulate(a.begin(), a.end(), 0LL, [](lint init, lint i) { return init + abs(i); }) << '\n';
  }
}