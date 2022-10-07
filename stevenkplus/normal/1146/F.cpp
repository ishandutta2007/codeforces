#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200100;
ll dp[MAXN][2];
const int MOD = 998244353;

vector<int> ch[MAXN];

ll suff[MAXN];
ll getdp(int n, int i) {
  ll &ret = dp[n][i];
  if (ret) return ret - 1;

  vector<int> &c = ch[n];
  int k = c.size();
  if (k == 0) return 1;

  ret = 1;
  for(int i = 0; i < k; ++i) {
    ret *= (getdp(c[i], 0) + getdp(c[i], 1)) % MOD;
    ret %= MOD;
  }

  suff[k] = 1;
  for (int i = k - 1; i >= 0; --i) {
    suff[i] = suff[i + 1] * getdp(c[i], 0) % MOD;
  }

  if (i == 0) {
    ll pref = 1;
    for(int i = 0; i < k; ++i) {
      ret -= pref * getdp(c[i], 1) % MOD * suff[i + 1] % MOD;
      ret %= MOD;
      pref = pref * getdp(c[i], 0) % MOD;
    }
  } else {
    ret -= suff[0];
    ret %= MOD;
  }


  if (ret < 0) ret += MOD;
  return ret++;
}

int main() {
  int n;
  cin >> n;
  for(int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    ch[p].push_back(i);
  }

  ll ans = getdp(1, 0);
  cout << ans << "\n";
}