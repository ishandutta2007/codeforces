#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> g(26);
    for (int i = 0; i < n - 1; ++i) {
      g[s[i] - 'a'].push_back(s[i + 1] - 'a');
      g[s[i + 1] - 'a'].push_back(s[i] - 'a');
    }
    [&] {
      for (auto&& v : g) {
        sort(begin(v), end(v));
        v.erase(unique(begin(v), end(v)), end(v));
        if (v.size() > 2) {
          cout << "NO\n";
          return;
        }
      }
      string res;
      while (true) {
        int si = -1;
        for (int i = 0; i < 26; ++i) {
          if (g[i].size() == 1) {
            si = i;
            break;
          }
        }
        if (si == -1) {
          if (any_of(begin(g), end(g), [](auto v) { return not v.empty(); })) {
            cout << "NO\n";
            return;
          }
          break;
        }
        int i = si;
        while (true) {
          res += 'a' + i;
          if (g[i].empty()) {
            break;
          }
          int j = g[i][0];
          g[i].erase(find(begin(g[i]), end(g[i]), j));
          g[j].erase(find(begin(g[j]), end(g[j]), i));
          i = j;
        }
      }
      for (char c = 'a'; c <= 'z'; ++c) {
        if (res.find(c) == string::npos) {
          res += c;
        }
      }
      assert(res.size() == 26);
      cout << "YES\n";
      cout << res << '\n';
    }();
  }
}