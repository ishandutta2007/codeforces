#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  vector<int> v;
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      v.push_back(cnt);
      cnt = 0;
    } else {
      ++cnt;
    }
  }
  v.push_back(cnt);
  if (v.size() == 1) {
    cout << s.size() << endl;
    return 0;
  }
  int tmp = 1ll * (v[0] + 1) * (v.back() + 1) % mod;
  v.pop_back();
  v.erase(v.begin());
  vector<int> dp(v.size()), stk, sum(v.size() + 1);
  for (int i = 0; i < v.size(); ++i) {
    if (i > 0) {
      dp[i] = 1ll * dp[i - 1] * (v[i] + 1) % mod;
    }
    int mx = stk.empty() ? -1 : v[stk[0]];
    if (v[i] > mx) {
      dp[i] = (dp[i] + v[i] - mx) % mod;
    }
    while (!stk.empty() && v[i] > v[stk.back()]) {
      dp[i] = (dp[i] + 1ll * (sum[stk.back()] - (stk.size() == 1 ? 0 : sum[stk[stk.size() - 2]])) * (v[i] - v[stk.back()])) % mod;
      stk.pop_back();
    }
    stk.push_back(i);
    sum[i + 1] = (sum[i] + dp[i]) % mod;
  }
  cout << ((sum.back() + 1ll) * tmp % mod + mod) % mod << endl;
}