#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr long double pi = acos(-1.0L);

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, r; cin >> n >> r;
  auto x = sin(pi / n);
  auto R = r * x / (1 - x);
  cout << fixed << setprecision(15) << R << '\n';
}