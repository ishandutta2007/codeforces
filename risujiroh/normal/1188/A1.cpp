#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> d(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    ++d[u], ++d[v];
  }
  for (int e : d) if (e == 2) {
    return cout << "NO" << '\n', 0;
  }
  cout << "YES" << '\n';
}