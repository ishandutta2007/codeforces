#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> p(n);
  for (int i = 0; i < 2 * n; ++i) {
    int a; cin >> a;
    if (a) p[a - 1] = i;
  }
  if (p[0] >= n) {
    bool b = true;
    for (int i = 1; p[0] + i < 2 * n; ++i) {
      if (p[i] != p[0] + i) {
        b = false;
        break;
      }
    }
    for (int i = 2 * n - p[0]; i < n; ++i) {
      if (p[i] >= i - n + p[0]) {
        b = false;
        break;
      }
    }
    if (b) {
      cout << p[0] - n << '\n';
      return 0;
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int curr = p[i] < n ? n - i : (p[i] - n + 1) + n - i;
    res = max(res, curr);
  }
  cout << res << '\n';
}