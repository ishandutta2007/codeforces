#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int n, m, k; cin >> n >> m >> k;
    V<> a(n); for (auto&& e : a) cin >> e;
    bool ok = [&]() -> bool {
      for (int i = 0; i < n - 1; ++i) {
        int x = max(a[i + 1] - k, 0);
        if (a[i] + m < x) {
          return false;
        }
        if (a[i] < x) {
          m -= x - a[i];
        } else {
          m += a[i] - x;
        }
      }
      return true;
    }();
    cout << (ok ? "YES" : "NO") << '\n';
  }
}