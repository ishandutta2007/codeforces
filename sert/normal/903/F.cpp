#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

constexpr int INF = (int)1e9 + 41;

void mne(int &a, int b) { if (b < a) a = b; }

void solve() {
  vector<pair<int, int>> k;
  vector<int> c(4);
  int n;
  cin >> n;
  for (int &x : c) cin >> x;
  for (int side = 1; side <= 4; side++) for (int x = 0; x + side <= 3; x++) for (int y = 0; y + side <= 4; y++) {
    int mask = 0;
    for (int i = y; i < y + side; i++)
      for (int j = x; j < x + side; j++)
        mask |= (1 << (4 * j + i));
    k.emplace_back(mask, c[side - 1]);
  }

  vector<string> s(4);
  for (auto &x : s) {
    cin >> x;
    for (int i = 0; i < 20; i++) x.push_back('.');
  }

  auto getVal = [&](int x) {
    int k = 0;
    for (int i = 0; i < 4; i++)
      if (s[i][x] == '*') 
        k |= (1 << i);
    return k;
  };
  int msk = (getVal(2) << 8) + (getVal(1) << 4) + getVal(0);
  int mx = (1 << 12) - 1;

  vector<vector<int>> dp(n + 12, vector<int>(1 << 12, INF));
  dp[2][msk] = 0;

  for (int i = 2; i < n; i++) {
    int nx = (getVal(i + 1) << 8);
    int mn = INF;
    for (int msk = mx; msk >= 0; msk--) {
      int curDp = dp[i][msk];
      if (curDp == INF) continue;
      mn = min(mn, curDp);
      if (!(msk & 15)) 
        mne(dp[i + 1][nx + (msk >> 4)], curDp);

      for (auto &[mask, cost] : k)
        mne(dp[i][msk & (mx ^ mask)], curDp + cost);      
    }

    mne(dp[i + 1][0], mn + c[3]);
  }

  cout << dp[n - 1][0] << "\n";
}

int main() {
#ifdef SERT
  for (int i = 0; i < 3; i++)
    solve();
#else
  solve();
#endif
}