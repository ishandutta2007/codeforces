#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> a(n, V<>(n));
  int t = 0;
  for (int k = 0; k < n / 4; ++k) {
    for (int i = 0; i < n; ++i) {
      a[i][4 * k] = t++;
      a[i][4 * k + 1] = t++;
      a[i][4 * k + 2] = t++;
      a[i][4 * k + 3] = t++;
    }
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    cout << a[i][j] << " \n"[j == n - 1];
  }
}