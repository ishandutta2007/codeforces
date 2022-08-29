#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  set<int> st;
  for (int i = 0; i < n; i++){
    bool ok = true;
    int t = a[i];
    while (t > 0){
      if (st.count(t) == 1){
        ok = false;
        break;
      }
      if (t % 2 == 1){
        t = (t - 1) / 2;
      } else if (t % 4 == 0){
        t /= 4;
      } else {
        break;
      }
    }
    if (ok){
      st.insert(a[i]);
    }
  }
  vector<long long> dp(p + 1);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i < p + 1; i++){
    dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
  }
  vector<long long> sum(p + 1);
  sum[0] = dp[0];
  for (int i = 1; i <= p; i++){
    sum[i] = (sum[i - 1] + dp[i]) % MOD;
  }
  long long ans = 0;
  for (int x : st){
   int D = 0;
    while (x > 0){
      x /= 2;
      D++;
    }
    if (D <= p){
      ans += sum[p - D];
    }
  }
  ans %= MOD;
  cout << ans << endl;
}