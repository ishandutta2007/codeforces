#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    s += s;
    vector<vector<int>> nxt(2 * n + 1, vector<int>(26, 2 * n));
    for (int i = 2 * n; i--; ) {
      nxt[i] = nxt[i + 1];
      nxt[i][s[i] - 'a'] = i;
    }
    int i = -1, res = 1;
    for (char c : t) {
      int ni = nxt[i + 1][c - 'a'];
      if (ni == 2 * n) {
        res = -1;
        break;
      }
      if (ni >= n) {
        ni -= n;
        ++res;
      }
      i = ni;
    }
    cout << res << '\n';
  }
}