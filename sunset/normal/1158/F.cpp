#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}

inline int mul(int x, int y) {
  return (int) ((long long) x * y % md);
}

inline int inv(int a) {
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) {
    u += md;
  }
  return u;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<bool> appear(c);
  int cnt = c;
  int p = 0;
  for (int i = 0; i < n; ++i) {
    if (!appear[a[i]]) {
      appear[a[i]] = true;
      --cnt;
    }
    if (!cnt) {
      cnt = c;
      ++p;
      for (int j = 0; j < c; ++j) {
        appear[j] = false;
      }
    }
  }
  vector<vector<int>> sum(c, vector<int>(n + 1));
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < n; ++j) {
      sum[i][j + 1] = sum[i][j] + (a[j] == i);
    }
  }
  vector<int> bin(n + 1);
  bin[0] = 1;
  for (int i = 0; i < n; ++i) {
    bin[i + 1] = mul(bin[i], 2);
  }
  vector<int> inv_bin(n + 1);
  for (int i = 1; i <= n; ++i) {
    inv_bin[i] = inv(bin[i] - 1);
  }
  vector<int> ans(n + 1);
  if (c <= 11) {
    vector<vector<int>> dp(p + 1, vector<int>(1 << c));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      vector<int> end(p);
      for (int j = 0; j < p; ++j) {
        end[j] = dp[j][((1 << c) - 1) ^ (1 << a[i])];
        add(ans[j + 1], mul(end[j], bin[n - i - 1]));
      }
      int u = min(p, i / c);
      for (int j = 0; j < 1 << c; ++j) {
        if (j >> a[i] & 1) {
          for (int k = 0; k <= u; ++k) {
            add(dp[k][j], dp[k][j]);
            add(dp[k][j], dp[k][j ^ (1 << a[i])]);
          }
        }
      }
      for (int j = 0; j < p; ++j) {
        add(dp[j + 1][0], end[j]);
      }
    }
  } else {
    vector<vector<int>> ways(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      int zeros = c;
      int coef = 1;
      for (int j = i; j < n; ++j) {
        if (sum[a[j]][j] == sum[a[j]][i]) {
          --zeros;
        } else {
          coef = mul(coef, inv_bin[sum[a[j]][j] - sum[a[j]][i]]);
        }
        ways[i][j] = zeros ? 0 : coef;
        coef = mul(coef, bin[sum[a[j]][j] - sum[a[j]][i] + 1] - 1);
      }
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int d = 1; d <= p; ++d) {
      vector<int> new_dp(n + 1);
      for (int i = d * c; i <= n; ++i) {
        long long sum = 0;
        for (int j = (d - 1) * c; j < i; ++j) {
          sum += mul(dp[j], ways[j][i - 1]);
        }
        new_dp[i] = sum % md;
      }
      swap(dp, new_dp);
      for (int i = d * c; i <= n; ++i) {
        add(ans[d], mul(dp[i], bin[n - i]));
      }
    }
  }
  add(ans[0], bin[n] - 1);
  for (int i = 0; i < n; ++i) {
    sub(ans[i], ans[i + 1]);
  }
  for (int i = 0; i <= n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}