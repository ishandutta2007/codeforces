#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int res = n;
    for (int r = 0; r < 3; ++r) {
      V<> c(n + 1);
      for (int i = 0; i < n; ++i) {
        c[i] = s[i] == "RGB"[(r + i) % 3];
      }
      for (int i = n - 1; i >= 0; --i) c[i] += c[i + 1];
      for (int i = 0; i + k <= n; ++i) {
        res = min(res, k - (c[i] - c[i + k]));
      }
    }
    cout << res << '\n';
  }
}