#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;
  int m = t.size();
  vector<int> F(k, -1);
  for (int i = 0; i < m; i++){
    F[t[i] - 'a'] = i;
  }
  vector<pair<int, int>> P(k);
  for (int i = 0; i < k; i++){
    P[i] = make_pair(F[i], i);
  }
  sort(P.begin(), P.end());
  for (int i = 0; i < n; i++){
    t += (char) ('a' + P[i % k].second);
  }
  vector<long long> dp(k, 0);
  for (int i = 0; i < m + n; i++){
    int p = t[i] - 'a';
    long long sum = 0;
    for (int j = 0; j < k; j++){
      sum += dp[j];
    }
    sum++;
    sum %= MOD;
    dp[p] = sum;
  }
  long long ans = 0;
  for (int i = 0; i < k; i++){
    ans += dp[i];
  }
  ans++;
  ans %= MOD;
  cout << ans << endl;
}