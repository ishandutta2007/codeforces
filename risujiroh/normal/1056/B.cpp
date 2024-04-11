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
  int n, m; cin >> n >> m;
  lint k = n / m;
  lint c = 0;
  for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) c += (i * i + j * j) % m == 0;
  lint res = c * k * k;
  lint r = n % m;
  c = 0;
  for (int i = 1; i <= m; ++i) for (int j = 1; j <= r; ++j) c += (i * i + j * j) % m == 0;
  res += 2 * c * k;
  c = 0;
  for (int i = 1; i <= r; ++i) for (int j = 1; j <= r; ++j) c += (i * i + j * j) % m == 0;
  res += c;
  cout << res << '\n';
}