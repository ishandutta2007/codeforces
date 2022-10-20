#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, k; cin >> n >> k;
  if (k < 3 or k > 2 * n - 1) return cout << 0 << '\n', 0;
  cout << min(k - 1, n) - (k - (k - 1) / 2) + 1 << '\n';
}