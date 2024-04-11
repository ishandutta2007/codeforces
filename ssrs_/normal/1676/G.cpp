#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 1; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    string s;
    cin >> s;
    vector<int> dp(n);
    for (int j = 0; j < n; j++){
      if (s[j] == 'B'){
        dp[j] = 1;
      } else {
        dp[j] = -1;
      }
    }
    for (int j = n - 1; j >= 1; j--){
      dp[a[j]] += dp[j];
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (dp[j] == 0){
        ans++;
      }
    }
    cout << ans << endl;
  }
}