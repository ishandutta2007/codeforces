#include <bits/stdc++.h>

using namespace std;

const int ALPHA = 26;
const int MAX = 250;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  string pattern;
  cin >> n >> q >> pattern;
  vector<vector<int>> nxt(n + 2, vector<int>(ALPHA, n + 1));
  for (int i = n - 1; ~i; --i) {
    nxt[i] = nxt[i + 1];
    nxt[i][pattern[i] - 'a'] = i + 1;
  }
  vector<vector<vector<int>>> dp(MAX + 1, vector<vector<int>>(MAX + 1, vector<int>(MAX + 1)));
  vector<string> s(3);
  while (q--) {
    string type;
    int who;
    cin >> type >> who;
    --who;
    if (type == "+") {
      string add;
      cin >> add;
      s[who] += add;
      for (int i = who == 0 ? s[0].size() : 0; i <= (int) s[0].size(); ++i) {
        for (int j = who == 1 ? s[1].size() : 0; j <= (int) s[1].size(); ++j) {
          for (int k = who == 2 ? s[2].size() : 0; k <= (int) s[2].size(); ++k) {
            dp[i][j][k] = n + 1;
            if (i) {
              dp[i][j][k] = min(dp[i][j][k], nxt[dp[i - 1][j][k]][s[0][i - 1] - 'a']);
            }
            if (j) {
              dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j - 1][k]][s[1][j - 1] - 'a']);
            }
            if (k) {
              dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k - 1]][s[2][k - 1] - 'a']);
            }
          }
        }
      }
    } else {
      s[who].pop_back();
    }
    cout << (dp[s[0].size()][s[1].size()][s[2].size()] == n + 1 ? "NO" : "YES") << "\n";
  }
  return 0;
}