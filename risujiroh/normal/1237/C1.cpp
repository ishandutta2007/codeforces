#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

lint sq(lint x) {
  return x * x;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> x(n), y(n), z(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];
  V<bool> used(n);
  for (int i = 0; i < n; ++i) if (not used[i]) {
    used[i] = true;
    lint mn = 1e18, mj = -1;
    for (int j = 0; j < n; ++j) if (not used[j]) {
      lint crr = sq(x[j] - x[i]) + sq(y[j] - y[i]) + sq(z[j] - z[i]);
      if (crr < mn) {
        mn = crr;
        mj = j;
      }
    }
    used[mj] = true;
    cout << i + 1 << ' ' << mj + 1 << '\n';
  }
}