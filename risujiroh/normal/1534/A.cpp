#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (auto&& e : s) cin >> e;
    bool found = false;
    for (int p : {0, 1}) {
      bool ok = true;
      for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
          ok &= s[i][j] == '.' or (~(i + j + p) & 1 and s[i][j] == 'R') or ((i + j + p) & 1 and s[i][j] == 'W');
      if (ok) {
        found = true;
        cout << "YES\n";
        for (int i = 0; i < h; ++i) {
          for (int j = 0; j < w; ++j) cout << ((i + j + p) & 1 ? 'W' : 'R');
          cout << '\n';
        }
        break;
      }
    }
    if (not found) cout << "NO\n";
  }
}