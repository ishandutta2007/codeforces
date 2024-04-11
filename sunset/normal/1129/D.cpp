#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  int each = sqrt(n);
  vector<int> belong(n);
  for (int i = 0; i < n; ++i) {
    belong[i] = i / each;
  }
  int m = belong[n - 1] + 1;
  vector<int> offset(m);
  vector<int> single(n);
  vector<vector<int>> pref(m, vector<int>(each + 1));
  vector<int> dp(n + 1);
  auto rebuild = [&](int b) {
    for (int i = 0; i <= each; ++i) {
      pref[b][i] = 0;
    }
    int min_single = n + 1;
    for (int i = b * each; i < (b + 1) * each && i < n; ++i) {
      min_single = min(min_single, single[i]);
    }
    offset[b] += min_single;
    for (int i = b * each; i < (b + 1) * each && i < n; ++i) {
      single[i] -= min_single;
      add(pref[b][single[i]], dp[i]);
    }
    for (int i = 1; i <= each; ++i) {
      add(pref[b][i], pref[b][i - 1]);
    }
  };
  auto modify = [&](int l, int r, int v) {
    if (belong[l] == belong[r]) {
      for (int i = l; i <= r; ++i) {
        single[i] += v;
      }
      rebuild(belong[l]);
    } else {
      for (int i = l; belong[i] == belong[l]; ++i) {
        single[i] += v;
      }
      rebuild(belong[l]);
      for (int i = belong[l] + 1; i <= belong[r] - 1; ++i) {
        offset[i] += v;
      }
      for (int i = r; belong[i] == belong[r]; --i) {
        single[i] += v;
      }
      rebuild(belong[r]);
    }
  };
  dp[0] = 1;
  rebuild(0);
  vector<int> last(n, -1), last_two(n, -1);
  for (int i = 0; i < n; ++i) {
    if (last[a[i]] != -1) {
      modify(last_two[a[i]] + 1, last[a[i]], -1);
    }
    modify(last[a[i]] + 1, i, 1);
    last_two[a[i]] = last[a[i]];
    last[a[i]] = i;
    for (int j = 0; j <= belong[i]; ++j) {
      int bound = min(each, k - offset[j]);
      if (bound >= 0) {
        add(dp[i + 1], pref[j][bound]);
      }
    }
    if (i + 1 < n) {
      rebuild(belong[i + 1]);
    }
  }
  cout << dp[n] << "\n";
  return 0;
}