#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int res = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] == 1 and a[i] == 2) {
      if (i - 2 < 0 or a[i - 2] != 3) res += 3;
      else res += 2;
    }
    if (a[i - 1] == 1 and a[i] == 3) res += 4;
    if (a[i - 1] == 2 and a[i] == 1) res += 3;
    if (a[i - 1] == 2 and a[i] == 3) return cout << "Infinite" << '\n', 0;
    if (a[i - 1] == 3 and a[i] == 1) res += 4;
    if (a[i - 1] == 3 and a[i] == 2) return cout << "Infinite" << '\n', 0;
  }
  cout << "Finite" << '\n';
  cout << res << '\n';
}