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
    string a, b;
    cin >> a >> b;
    vector<int> res;
    auto op = [&](int p) {
      for (int i = 0; i < p; ++i) {
        a[i] ^= 1;
      }
      reverse(begin(a), begin(a) + p);
      res.push_back(p);
    };
    for (int i = n; i--; ) {
      if (a[i] == b[i]) continue;
      if (a[0] != b[i]) {
        op(i + 1);
        continue;
      }
      op(1);
      op(i + 1);
    }
    DEBUG(a, b);
    cout << size(res);
    for (auto e : res) {
      cout << ' ' << e;
    }
    cout << '\n';
  }
}