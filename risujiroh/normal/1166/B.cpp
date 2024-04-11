#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int k; cin >> k;
  for (int n = 5; n <= k; ++n) if (k % n == 0) {
    int m = k / n;
    if (m < 5) continue;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      cout << "aeiou"[(i + j) % 5];
    }
    cout << '\n';
    return 0;
  }
  cout << -1 << '\n';
}