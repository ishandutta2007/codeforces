#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int n;
int c[205][205];
int pre[205][205];
int dp[205][205];
int vis[205][205];
int root[205][205];
int ans[205];

int Get(int x1, int y1, int x2, int y2) {
  return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

int C(auto s1, auto s2) {
  return Get(s1.first, s2.first, s1.second, s2.second);
}

int CO(auto p) {
  return C(p, pair{1, p.first - 1}) + C(p, pair{p.second + 1, n});
}

void go(int l, int r) {
  // cout << "go " << l << ' ' << r << endl;
  if (vis[l][r]) return;
  vis[l][r] = 1;

  if (l >= r) {
    return;
  }

  int mn = LLONG_MAX;
  int rta = -1;
  for (int rt = l; rt <= r; ++rt) {
    go(l, rt - 1);
    go(rt + 1, r);
    int ldp = dp[l][rt - 1];
    int rdp = dp[rt + 1][r];

    int dpc = ldp + rdp + CO(pair{l, rt - 1}) + CO(pair{rt + 1, r});

    if (dpc < mn) {
      mn = dpc;
      rta = rt;
    }
  }

  // cout << "l r mn rta " << l << ' ' << r << ' ' << mn << ' ' << rta << endl;

  dp[l][r] = mn;
  root[l][r] = rta;
}

int getroot(int l, int r) {
  if (l == r) return l;
  if (l > r) return 0;
  int rt = root[l][r];
  if (rt != l) ans[getroot(l, rt - 1)] = rt;
  if (rt != r) ans[getroot(rt + 1, r)] = rt;
  return rt;
}

int32_t main() {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
      pre[i][j] = c[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
  }

  go(1, n);
  getroot(1, n);

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }

}