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
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto&& e : b) cin >> e;
    vector<int> a(m, -1);
    for (int k = 0; k < 26; ++k) {
      for (int i = 0; i < m; ++i) {
        if (b[i] == 0) {
          a[i] = k;
          b[i] = -1;
        }
      }
      for (int i = 0; i < m; ++i) {
        if (a[i] != k) continue;
        for (int j = 0; j < m; ++j) {
          if (b[j] == -1) continue;
          b[j] -= abs(j - i);
        }
      }
    }
    vector<int> cnt(26);
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    int nxt = 25;
    string res(m, '?');
    for (int k = 0; k < 26; ++k) {
      int c = count(begin(a), end(a), k);
      if (c == 0) break;
      while (cnt[nxt] < c) {
        --nxt;
      }
      for (int i = 0; i < m; ++i) {
        if (a[i] == k) {
          res[i] = 'a' + nxt;
        }
      }
      --nxt;
    }
    cout << res << '\n';
  }
}