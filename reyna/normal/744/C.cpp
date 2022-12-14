// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 1 << 16, M = 300, mod = (int) 0;
int col[N], r[N], b[N], rs[N], bs[N];
int dp[N][M];
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int sr = 0, sb = 0;
  for (int j = 0; j < (1 << n); ++j)
    for (int i = 0; i <= n * n; ++i)
      dp[j][i] = -1e9;
  for (int j = 0; j < n; ++j) {
    char c;
    cin >> c;
    col[j] = (c == 'R');
    cin >> r[j] >> b[j];
    sr += r[j];
    sb += b[j];
  }
  dp[0][0] = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int j = 0; j < n; ++j) {
      if (mask >> j & 1) {
        rs[mask] += col[j];
        bs[mask] += col[j] ^ 1;
      }
    }
  }
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int last = 0; last < n; ++last) if (mask >> last & 1) {
      for (int save = min(r[last], rs[mask ^ (1 << last)]); save <= n * n; ++save) {
        dp[mask][save] = max(dp[mask ^ (1 << last)][save - min(r[last], rs[mask ^ (1 << last)])] + min(b[last], bs[mask ^ (1 << last)]), dp[mask][save]);
      }
    }
  }
  int res = 1e9;
  for (int save = 0; save <= n * n; ++save) {
    res = min(res, max(sr - save, sb - dp[(1 << n) - 1][save]));
  }
  cout << n + res << endl;
}