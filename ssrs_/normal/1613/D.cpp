#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> dp1(n + 2, 0);
    dp1[0] = 1;
    vector<long long> dp2(n + 2, 0);
    long long ans = 0;
    for (int j = 0; j < n; j++){
      if (a[j] >= 1){
        ans += dp2[a[j] - 1];
        dp2[a[j] - 1] += dp2[a[j] - 1];
      }
      ans += dp2[a[j] + 1];
      dp2[a[j] + 1] += dp2[a[j] + 1];
      dp2[a[j] + 1] %= MOD;
      if (a[j] >= 1){
        ans += dp1[a[j] - 1];
        dp2[a[j] - 1] += dp1[a[j] - 1];
        dp2[a[j] - 1] %= MOD;
      }
      ans += dp1[a[j]] + dp1[a[j] + 1];
      ans %= MOD;
      dp1[a[j] + 1] += dp1[a[j]] + dp1[a[j] + 1];
      dp1[a[j] + 1] %= MOD;
    }
    cout << ans << "\n";
  }
}