#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
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
    vector<int> s(n + 1);
    s[0] = 0;
    for (int j = 0; j < n; j++){
      s[j + 1] = s[j] ^ a[j];
    }
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int j = 0; j < n; j++){
      if (a[j] == 0){
        dp[j + 1] = min(dp[j + 1], dp[j]);
      } else {
        dp[j + 1] = min(dp[j + 1], dp[j] + 1);
      }
      for (int k = j + 1; k <= n; k++){
        if (s[k] == s[j]){
          dp[k] = min(dp[k], dp[j] + (k - j - 1));
        }
      }
    }
    cout << dp[n] << endl;
  }
}