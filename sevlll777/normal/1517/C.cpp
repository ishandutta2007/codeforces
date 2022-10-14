#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> P(n);
  for (int i = 0; i < n; i++) cin >> P[i];
  vector<vector<int>> ans(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    int x = i, y = i;
    int vl = P[i];
    while (P[i]--) {
      ans[x][y] = vl;
      if (y > 0 && ans[x][y - 1] == 0) {
        y--;
      } else {
        x++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}