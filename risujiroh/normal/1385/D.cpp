#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> f(2 * n);
    for (int i = 0; i < n; ++i) {
      f[n + i] = s[i] != 'a' + __lg(n);
    }
    for (int k = n; k-- > 1; ) {
      int w = n >> __lg(k);
      int l = (k - n / w) * w, r = l + w;
      int m = (l + r) / 2;
      char c = 'a' + __lg(k);
      int cl = count_if(begin(s) + l, begin(s) + m, [&](char e) { return e != c; });
      int cr = count_if(begin(s) + m, begin(s) + r, [&](char e) { return e != c; });
      f[k] = min(cl + f[2 * k + 1], f[2 * k] + cr);
    }
    cout << f[1] << '\n';
  }
}