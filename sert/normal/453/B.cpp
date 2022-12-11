#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 41;

const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int getPrimes(int x) {
  int msk = 0;
  for (int i = 0; i < (int)primes.size(); i++) {
    if (x % primes[i] == 0) msk |= (1 << i);
  }
  return msk;
}

void solve() {  
  vector<int> bak(60, -1);
  for (int i = 0; i < (int)primes.size(); i++) bak[primes[i]] = i;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<vector<int>> dp(n + 1, vector<int>(1 << primes.size(), INF));
  vector<vector<int>> pr(n + 1, vector<int>(1 << primes.size(), INF));
  vector<int> pmsk(60);
  for (int i = 1; i < (int)pmsk.size(); i++) pmsk[i] = getPrimes(i);
  dp[0][0] = 0;  
  for (int i = 0; i < n; i++) {
    for (int msk = 0; msk < (1 << primes.size()); msk++) {
      if (dp[i][msk] == INF) continue;      
      for (int x = 1; x < 59; x++) {
        if (msk & pmsk[x]) continue;
        int nw = dp[i][msk] + abs(a[i] - x);
        int nw_msk = (msk | pmsk[x]);
        if (nw < dp[i + 1][nw_msk]) {
          dp[i + 1][nw_msk] = nw;
          pr[i + 1][nw_msk] = x;
        }
      }
    }
  }

  int msk = min_element(dp[n].begin(), dp[n].end()) - dp[n].begin();
  vector<int> ans;
  for (int i = n; i > 0; i--) {
    int x = pr[i][msk];
    ans.push_back(x);
    msk ^= pmsk[x];
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SERT
  for (int i = 0; i < 2; i++) solve();
#else
  solve();
#endif
}