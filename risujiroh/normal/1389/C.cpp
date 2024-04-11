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
    int n = size(s);
    vector<int> cnt(10);
    for (char c : s) {
      ++cnt[c - '0'];
    }
    int res = *max_element(begin(cnt), end(cnt));
    for (int x = 0; x < 10; ++x) {
      for (int y = 0; y < 10; ++y) {
        int cur = 0;
        for (char c : s) {
          cur += (cur % 2 == 0 and c - '0' == x) or (cur & 1 and c - '0' == y);
        }
        res = max(res, cur / 2 * 2);
      }
    }
    cout << n - res << '\n';
  }
}