#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    string s, t;
    cin >> n >> m >> s;
    for (int i = 0; i < n / 2 - (m - 1); ++i) {
      t.push_back('(');
    }
    for (int i = 0; i < n / 2 - (m - 1); ++i) {
      t.push_back(')');
    }
    for (int i = 0; i < m - 1; ++i) {
      t.push_back('(');
      t.push_back(')');
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        int j = i;
        while (j < n && s[j] != t[i]) {
          j++;
        }
        reverse(s.begin() + i, s.begin() + j + 1);
        ans.emplace_back(i + 1, j + 1);
      }
    }
    cout << ans.size() << "\n";
    for (auto p : ans) {
      cout << p.first << " " << p.second << "\n";
    }
  }
  return 0;
}