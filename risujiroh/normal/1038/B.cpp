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
  if (n <= 2) return cout << "No" << '\n', 0;
  cout << "Yes" << '\n';
  if (n & 1) {
    cout << 1 << ' ' << n << '\n';
    cout << n - 1 << ' ';
    for (int i = 1; i < n; i++) cout << i << (i != n - 1 ? ' ' : '\n');
  } else {
    cout << 1 << ' ' << n / 2 << '\n';
    cout << n - 1 << ' ';
    for (int i = 1; i < n + 1; i++) if (i != n / 2) cout << i << (i != n ? ' ' : '\n');
  }
}