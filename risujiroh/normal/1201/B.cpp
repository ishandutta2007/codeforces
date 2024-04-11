#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  lint s = accumulate(begin(a), end(a), 0LL);
  if (s & 1) return cout << "NO" << '\n', 0;
  for (int e : a) {
    if (2 * e > s) return cout << "NO" << '\n', 0;
  }
  cout << "YES" << '\n';
}