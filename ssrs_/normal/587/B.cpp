#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long l, k;
  cin >> n >> l >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<tuple<int, int, int>> pos;
  for (int i = 0; i < n; i++){
    pos.push_back(make_tuple(a[i], 0, i));
    pos.push_back(make_tuple(a[i], 1, i));
  }
  sort(pos.begin(), pos.end());
  vector<vector<long long>> dp(k, vector<long long>(n, 0));
  for (int i = 0; i < n; i++){
    dp[0][i] = 1;
  }
  for (int i = 1; i < k; i++){
    long long sum = 0;
    for (int j = 0; j < n * 2; j++){
      int type = get<1>(pos[j]);
      int id = get<2>(pos[j]);
      if (type == 0){
        sum += dp[i - 1][id];
        sum %= MOD;
      }
      if (type == 1){
        dp[i][id] = sum;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < k; i++){
    for (int j = 0; j < n; j++){
      int pos = i * n + j;
      if (pos < l){
        long long m = (l - j - i * n - 1) / n + 1;
        m %= MOD;
        ans += m * dp[i][j] % MOD;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}