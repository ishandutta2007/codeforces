#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<string> ans(h - (~h & 1), string(w - (~w & 1), '0'));
    for (int i = 0; i < int(size(ans)); i += 2) {
      ans[i][0] = '1';
      ans[i].back() = '1';
    }
    for (int j = 0; j < int(size(ans[0])); j += 2) {
      ans[0][j] = '1';
      ans.back()[j] = '1';
    }
    if (~h & 1) {
      ans.insert(begin(ans) + 1, string(w - (~w & 1), '0'));
    }
    if (~w & 1) {
      for (auto&& e : ans) e.insert(begin(e) + 1, '0');
    }
    for (auto&& e : ans) cout << e << '\n';
    cout << '\n';
  }
}