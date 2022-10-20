#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> c(n + 1, vector<int>(26));
  for (int i = n; i--; ) {
    c[i] = c[i + 1];
    ++c[i][s[i] - 'a'];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    auto res = [&] {
      if (r - l == 1) {
        return "Yes";
      }
      if (s[l] != s[r - 1]) {
        return "Yes";
      }
      int other = 0;
      set<int> se;
      for (int j = 0; j < 26; ++j) {
        if (s[l] - 'a' == j) {
          continue;
        }
        other += c[l][j] - c[r][j];
        if (c[l][j] - c[r][j]) {
          se.insert(j);
        }
      }
      if (other < 2) {
        return "No";
      }
      if (se.size() >= 2) {
        return "Yes";
      }
      return "No";
    }();
    cout << res << '\n';
  }
}