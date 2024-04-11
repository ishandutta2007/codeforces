#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<lint> a(n, V<lint>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    cin >> a[i][j];
  }
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n, k = (i + 2) % n;
    lint res = sqrt(a[i][j] * a[i][k] / a[j][k]) + 0.5;
    cout << res << " \n"[i == n - 1];
  }
}