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
  cout << fixed << setprecision(20);
  string s(5000, 'a');
  cin >> s;
  int n = s.size();
  s += s;
  double res = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    vector<int> ks;
    for (int k = 0; k < n; ++k) {
      if (s[k] == c) {
        ks.push_back(k);
      }
    }
    int mx = 0;
    vector<int> cnt(26);
    for (int i = 1; i < n; ++i) {
      fill(begin(cnt), end(cnt), 0);
      for (int k : ks) {
        ++cnt[s[k + i] - 'a'];
      }
      mx = max<int>(mx, count(begin(cnt), end(cnt), 1));
    }
    res += mx;
  }
  res /= n;
  cout << res << '\n';
}