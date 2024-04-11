#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> x, y;
  for (int i = 0; i < n; i++){
    if (a[i] == 1){
      x.push_back(i);
    } else {
      y.push_back(i);
    }
  }
  int c1 = x.size();
  int c2 = y.size();
  vector<vector<int>> dp(c1 + 1, vector<int>(c2 + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i <= c1; i++){
    for (int j = 0; j < c2; j++){
      dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
      if (i < c1){
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(x[i] - y[j]));
      }
    }
  }
  cout << dp[c1][c2] << endl;
}