#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(3, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    dp[i + 1][0] = max({dp[i][0], dp[i][1], dp[i][2]});
    if (a[i] == 1 || a[i] == 3){
      dp[i + 1][1] = max(dp[i][0], dp[i][2]) + 1;
    }
    if (a[i] == 2 || a[i] == 3){
      dp[i + 1][2] = max(dp[i][0], dp[i][1]) + 1;
    }
  }
  cout << n - max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}