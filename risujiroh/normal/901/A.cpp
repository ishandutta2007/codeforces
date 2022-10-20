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
  int h;
  cin >> h;
  vector<int> a(h + 1);
  for (auto&& e : a) {
    cin >> e;
  }
  for (int i = 1; i < h; ++i) {
    if (min(a[i], a[i + 1]) >= 2) {
      cout << "ambiguous\n";
      vector<vector<int>> vs(h + 1);
      int nxt = 0;
      for (int j = 0; j <= h; ++j) {
        vs[j].resize(a[j]);
        iota(begin(vs[j]), end(vs[j]), nxt);
        nxt = vs[j].back() + 1;
      }
      cout << '0';
      for (int j = 1; j <= h; ++j) {
        for (int v : vs[j]) {
          cout << ' ' << vs[j - 1][0] + 1;
        }
      }
      cout << '\n';
      cout << '0';
      for (int j = 1; j <= h; ++j) {
        if (j == i + 1) {
          bool first = true;
          for (int v : vs[j]) {
            if (exchange(first, false)) {
              cout << ' ' << vs[j - 1][0] + 1;
            } else {
              cout << ' ' << vs[j - 1][1] + 1;
            }
          }
        } else {
          for (int v : vs[j]) {
            cout << ' ' << vs[j - 1][0] + 1;
          }
        }
      }
      cout << '\n';
      exit(0);
    }
  }
  cout << "perfect\n";
}