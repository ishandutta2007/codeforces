#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    int B = 1;
    while ((B + 1) * (B + 2) / 2 <= n){
      B++;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(B + 1, -INF));
    dp[n][0] = INF;
    for (int j = n - 1; j >= 0; j--){
      for (int k = 0; k <= B; k++){
        dp[j][k] = dp[j + 1][k];
        if (k > 0){
          if (j + k <= n){
            long long sum = S[j + k] - S[j];
            if (sum < dp[j + k][k - 1]){
              dp[j][k] = max(dp[j][k], sum);
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= B; i++){
      if (dp[0][i] != -INF){
        ans = i;
      }
    }
    cout << ans << endl;
  }
}