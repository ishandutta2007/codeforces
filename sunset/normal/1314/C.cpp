#include <bits/stdc++.h>

using namespace std;

template<typename T>
vector<int> z_algorithm(const T& a) {
  int n = a.size();
  vector<int> z(n);
  z[0] = n;
  int l = -1, r = -1;
  for (int i = 1; i < n; ++i) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < n && a[i + z[i]] == a[z[i]]) {
      ++z[i];
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

const int N = 523456;

int tot = 1, pr[N], nxt[N][26];
char val[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  long long k;
  string s;
  cin >> n >> m >> k >> s;
  for (int i = 0; i < n; ++i) {
    int x = 1;
    for (int j = i; j < n; ++j) {
      if (!nxt[x][s[j] - 'a']) {
        nxt[x][s[j] - 'a'] = ++tot;
        val[tot] = s[j];
        pr[tot] = x;
      }
      x = nxt[x][s[j] - 'a'];
    }
  }
  vector<int> order;
  function<void(int)> dfs = [&](int v) {
    for (int i = 0; i < 26; ++i) {
      if (nxt[v][i]) {
        order.push_back(nxt[v][i]);
        dfs(nxt[v][i]);
      }
    }
  };
  dfs(1);
  auto get = [&](int v) {
    string res;
    while (v != 1) {
      res.push_back(val[v]);
      v = pr[v];
    }
    reverse(res.begin(), res.end());
    return res;
  };
  auto check = [&](string t) {
    vector<int> z = z_algorithm(t + s);
    vector<int> lcp(n);
    for (int i = 0; i < n; ++i) {
      lcp[i] = min(z[i + t.size()], (int) t.size() - 1);
    }
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int tt = 0; tt < m; ++tt) {
      vector<long long> new_dp(n + 1);
      for (int i = 0; i < n; ++i) {
        if (s[i + lcp[i]] >= t[lcp[i]]) {
          new_dp[i + lcp[i] + 1] = min(k, new_dp[i + lcp[i] + 1] + dp[i]);
        }
      }
      for (int i = 1; i <= n; ++i) {
        new_dp[i] = min(k, new_dp[i] + new_dp[i - 1]);
      }
      swap(dp, new_dp);
    }
    return dp[n] >= k;
  };
  int l = 0, r = order.size() - 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    string t = get(order[mid]);
    if (check(t)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << get(order[l]) << "\n";
  return 0;
}