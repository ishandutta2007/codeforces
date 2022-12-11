#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 123;
const int M = 26;

ll dp[N][N];
ll num[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  ll k;
  string s;
  cin >> n >> k >> s;

  for (int pos = 0; pos < n; pos++) dp[1][pos] = 1;

  for (int len = 2; len <= n; len++) {
    for (int pos = 0; pos < n; pos++) {
      vector<bool> u(M, false);
      for (int i = pos - 1; i >= 0; i--) {
        if (u[s[i] - 'a']) continue;
        u[s[i] - 'a'] = true;
        dp[len][pos] += dp[len - 1][i];
      }
    }
  }

  // cout << "dp" << endl;


  for (int len = n; len >= 1; len--) {
    vector<bool> u(M, false);
    for (int i = n - 1; i >= 0; i--) {
      if (u[s[i] - 'a']) continue;
      u[s[i] - 'a'] = true;

      num[len] += dp[len][i];
    }
  }

  // cout << "num" << endl;

  ll cost = 0;
  for (int len = n; k > 0 && len >= 1; len--) {
    if (num[len] >= k) {
      cost += k * (n - len);
      k = 0;
    } else {
      cost += num[len] * (n - len);
      k -= num[len];
    }
  }

  if (k > 0) {
    cost += n;
    k--;
  }

  if (k > 0)
    cout << "-1\n";
  else
    cout << cost << "\n";
}