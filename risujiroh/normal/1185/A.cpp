#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  V<> a(3); for (auto&& e : a) cin >> e;
  int d; cin >> d;
  sort(begin(a), end(a));
  int res = max(d - (a[2] - a[1]), 0) + max(d - (a[1] - a[0]), 0);
  cout << res << '\n';
}