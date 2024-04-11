#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(2 * n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  if (a[0] == a.back()) cout << -1 << '\n';
  else {
    for (int i = 0; i < 2 * n; ++i) cout << a[i] << " \n"[!(2 * n + ~i)];
  }
}