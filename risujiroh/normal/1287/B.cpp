#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  map<string, int> mp;
  for_each(begin(s), end(s), [&](string& e) {
    cin >> e;
    ++mp[e];
  });
  int res = 0;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      string t(k, '?');
      for (int p = 0; p < k; ++p) {
        if (s[i][p] == s[j][p]) {
          t[p] = s[i][p];
        } else {
          for (char c : "SET"s) {
            if (c != s[i][p] and c != s[j][p]) {
              t[p] = c;
              break;
            }
          }
        }
      }
      if (mp.count(t)) {
        res += mp[t];
      }
    }
  }
  res /= 3;
  cout << res << '\n';
}