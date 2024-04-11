#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int s = a[0], k = 1;
  for (int i = 1; i < n; ++i) if (a[0] >= 2 * a[i]) {
    s += a[i];
    ++k;
  }
  if (2 * s > accumulate(begin(a), end(a), 0)) {
    cout << k << '\n';
    cout << 1;
    for (int i = 1; i < n; ++i) if (a[0] >= 2 * a[i]) {
      cout << ' ' << i + 1;
    }
    cout << '\n';
  } else {
    cout << 0 << '\n';
  }
}