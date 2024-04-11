#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template<class T> bool prime(T n) {
  if (n < 2 or n > 2 and n % 2 == 0) return false;
  for (T i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
  return true;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int t; cin >> t;
  for (int it = 0; it < t; it++) {
    lint a, b; cin >> a >> b;
    cout << (a - b == 1 and prime(a + b) ? "YES" : "NO") << '\n';
  }
}