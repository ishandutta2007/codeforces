#include <bits/stdc++.h>

using namespace std;

const int MaxN = 305;
const int MaxL = 75;

int n, t, ptr;
int a[MaxN];
int dp[MaxL][MaxN][MaxN];
int cur[MaxN];
vector < int > b;

void combine(int res, int l, int r) {
  for (int i = 0; i < (int)b.size(); ++i) {
    for (int j = i; j < (int)b.size(); ++j) {
      vector < int > le, ri;
      for (int k = i; k <= j; ++k) {
        le.push_back(dp[l][i][k]);
      }
      for (int k = i; k <= j; ++k) {
        ri.push_back(dp[r][k][j]);
      }
      for (int k = 0; k < (int)le.size(); ++k) {
        if (k > 0) {
          le[k] = max(le[k], le[k - 1]);
        }
      }
      for (int k = (int)ri.size() - 1; k >= 0; --k) {
        if (k + 1 < (int)ri.size()) {
          ri[k] = max(ri[k], ri[k + 1]);
        }
      }
      for (int k = 0; k < (int)le.size(); ++k) {
        dp[res][i][j] = max(dp[res][i][j], le[k] + ri[k]);
      }
    }
  }
}

int solve(int t) {
  if (t == 1) {
    return 0;
  }
  int ret = ++ptr, a, b = 0;
  if (t % 2 == 1) {
    a = solve(t - 1);
  } else {
    b = a = solve(t / 2);
  }
  combine(ret, a, b);
  return ret;
}

int main() {
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    int be = a[i];
    memset(cur, -1, sizeof(cur));
    cur[be] = 1;
    for (int j = i + 1; j < n; ++j) {
      int curv = -1;
      for (int lbe = 0; lbe <= a[j]; ++lbe) {
        if (cur[lbe] != -1) {
          curv = max(curv, cur[lbe] + 1);
        }
      }
      cur[a[j]] = max(cur[a[j]], curv);
    }
    for (int j = 0; j < (int)b.size(); ++j) {
      dp[0][be][j] = max(dp[0][be][j], cur[j]);
    }
  }
  int id = solve(t);
  int ans = 1;
  for (int i = 0; i < (int)b.size(); ++i) {
    for (int j = 0; j < (int)b.size(); ++j) {
      if (dp[id][i][j] != -1) {
        ans = max(ans, dp[id][i][j]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}