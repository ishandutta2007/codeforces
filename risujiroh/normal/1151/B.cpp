#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a(n, V<>(m));
  VV<> b(n);
  bool f = false;
  int r = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> a[i][j];
    b[i] = a[i];
    sort(begin(b[i]), end(b[i]));
    b[i].erase(unique(begin(b[i]), end(b[i])), end(b[i]));
    if (b[i].size() >= 2) {
      r = i;
      f = true;
    }
  }
  if (!f) {
    int s = 0;
    for (int i = 0; i < n; ++i) s ^= b[i][0];
    if (s) {
      cout << "TAK" << '\n';
      for (int i = 0; i < n; ++i) cout << 1 << " \n"[i == n - 1];
    } else {
      cout << "NIE" << '\n';
    }
  } else {
    cout << "TAK" << '\n';
    int s = 0;
    for (int i = 0; i < n; ++i) if (i != r) s ^= a[i][0];
    for (int i = 0; i < n; ++i) {
      if (i == r) {
        for (int j = 0; j < m; ++j) if (s ^ a[i][j]) {
          cout << j + 1;
          break;
        }
      } else {
        cout << 1;
      }
      cout << " \n"[i == n - 1];
    }
  }
}