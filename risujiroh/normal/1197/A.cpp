#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    V<> a(n); for (auto&& e : a) cin >> e;
    sort(rbegin(a), rend(a));
    if (n == 2) {
      cout << 0 << '\n';
    } else {
      int k = min(a[1] - 1, n - 2);
      cout << max(k, 0) << '\n';
    }
  }
}