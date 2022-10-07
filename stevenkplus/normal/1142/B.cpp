#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXK = 21;
const int MAXN = 200100;
int p[MAXN];
int ar[MAXN];
int pos[MAXN];
int dp[MAXN][MAXK];
int ans[MAXN];

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    p[x] = i;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    ar[i] = p[x];
  }
  for (int i = 0; i < n; ++i) {
    pos[i] = 1000 << 20;
  }
  for(int i = m - 1; i >= 0; --i) {
    int nxt = (ar[i] + 1) % n;
    dp[i][0] = pos[nxt] - i;
    pos[ar[i]] = i;
  }

  for(int k = 0; k  + 1 < MAXK; ++k) {
    for(int i = 0; i < m; ++i) {
      dp[i][k + 1] = dp[i][k];
      if (i + dp[i][k] < m) dp[i][k + 1] += dp[i + dp[i][k]][k];
    }
  }

  ans[m] = 1000 << 20;
  for(int i = m - 1; i >= 0; --i) {
    ans[i] = 0;
    for(int j = 0; j < MAXK; ++j) {
      if (((n - 1) >> j) & 1) {
        if (i + ans[i] < m)
          ans[i] += dp[i + ans[i]][j];
        else ans[i] = 1000 << 20;
      }
    }
    if (i + ans[i] > m) ans[i] = 1000 << 20;
    ans[i] = min(ans[i], ans[i + 1] + 1);
    // cout << "ANS"<<i<< " " << ans[i] << "\n";
  }

  for(int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    if (ans[a] + 1 <= b - a) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << "\n";
}