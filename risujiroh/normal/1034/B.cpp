#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, m; cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    V<> a = {0, 0, 0, 0, 2, 4};
    cout << m / 6 * 6 + a[m % 6] << '\n';
  } else if (n == 2) {
    if (m == 2) cout << 0 << '\n';
    else if (m == 3) cout << 4 << '\n';
    else if (m == 7) cout << 12 << '\n';
    else cout << n * m << '\n';
  } else {
    cout << n * m - (n * m & 1) << '\n';
  }
}