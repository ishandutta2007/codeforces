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
    vector<int> cnt(3);
    for (char c : s) {
      ++cnt[string("RPS").find(c)];
    }
    int mi = max_element(begin(cnt), end(cnt)) - begin(cnt);
    cout << string(size(s), "PSR"[mi]) << '\n';
  }
}