#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> pos;
    for (int i = 0; i < n; ++i)
      if (s[i] == '1') pos.push_back(i);
    for (int z = 0; z < int(size(pos)); ++z) {
      if (z == 0) {
        for (int i = 1; i <= m; ++i) {
          if (pos[z] - i < 0) break;
          s[pos[z] - i] = '1';
        }
      }
      if (z + 1 == int(size(pos))) {
        for (int i = 1; i <= m; ++i) {
          if (pos[z] + i >= n) break;
          s[pos[z] + i] = '1';
        }
      } else {
        for (int i = 1; i <= m; ++i) {
          if (pos[z] + i >= pos[z + 1] - i) break;
          s[pos[z] + i] = '1';
          s[pos[z + 1] - i] = '1';
        }
      }
    }
    cout << s << '\n';
  }
}