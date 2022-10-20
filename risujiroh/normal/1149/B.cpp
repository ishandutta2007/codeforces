#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  VV<> nxt(n, V<>(26, n));
  for (int i = n - 1; i >= 0; --i) {
    if (i + 1 < n) nxt[i] = nxt[i + 1];
    nxt[i][s[i] - 'a'] = i;
  }
  auto fn = [&](int l, char ch) -> int {
    if (l >= n) return n + 1;
    return nxt[l][ch - 'a'] + 1;
  };

  static int dp[251][251][251];
  string x, y, z;
  while (q--) {
    char op; cin >> op;
    if (op == '+') {
      int i; cin >> i, --i;
      char ch; cin >> ch;
      if (i == 0) {
        x += ch;
        int m = x.size();
        for (int b = 0; b <= (int)y.size(); ++b) for (int c = 0; c <= (int)z.size(); ++c) {
          dp[m][b][c] = fn(dp[m - 1][b][c], ch);
          if (b) dp[m][b][c] = min(dp[m][b][c], fn(dp[m][b - 1][c], y[b - 1]));
          if (c) dp[m][b][c] = min(dp[m][b][c], fn(dp[m][b][c - 1], z[c - 1]));
        }
      }
      if (i == 1) {
        y += ch;
        int m = y.size();
        for (int a = 0; a <= (int)x.size(); ++a) for (int c = 0; c <= (int)z.size(); ++c) {
          dp[a][m][c] = fn(dp[a][m - 1][c], ch);
          if (a) dp[a][m][c] = min(dp[a][m][c], fn(dp[a - 1][m][c], x[a - 1]));
          if (c) dp[a][m][c] = min(dp[a][m][c], fn(dp[a][m][c - 1], z[c - 1]));
        }
      }
      if (i == 2) {
        z += ch;
        int m = z.size();
        for (int a = 0; a <= (int)x.size(); ++a) for (int b = 0; b <= (int)y.size(); ++b) {
          dp[a][b][m] = fn(dp[a][b][m - 1], ch);
          if (a) dp[a][b][m] = min(dp[a][b][m], fn(dp[a - 1][b][m], x[a - 1]));
          if (b) dp[a][b][m] = min(dp[a][b][m], fn(dp[a][b - 1][m], y[b - 1]));
        }
      }
    } else {
      int i; cin >> i, --i;
      if (i == 0) x.pop_back();
      if (i == 1) y.pop_back();
      if (i == 2) z.pop_back();
    }
    cout << (dp[x.size()][y.size()][z.size()] <= n ? "YES" : "NO") << '\n';
  }
}