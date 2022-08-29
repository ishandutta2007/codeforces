#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> sum(n + 1, vector<int>(26, 0));
    for (int j = 0; j < n; j++){
      sum[j + 1] = sum[j];
      sum[j + 1][s[j] - 'a']++;
    }
    int f = __builtin_ctz(n);
    vector<vector<int>> dp(f + 1, vector<int>(n, INF));
    for (int j = 0; j < n; j++){
      if (s[j] == 'a' + f){
        dp[0][j] = 0;
      } else {
        dp[0][j] = 1;
      }
    }
    for (int j = 0; j < f; j++){
      for (int k = 0; k < n; k += (1 << (j + 1))){
        int mid = k + (1 << j);
        int right = k + (1 << (j + 1));
        dp[j + 1][k] = min(dp[j][k] + (1 << j) - (sum[right][f - j - 1] - sum[mid][f - j - 1]), dp[j][mid] + (1 << j) - (sum[mid][f - j - 1] - sum[k][f - j - 1]));
      }
    }
    cout << dp[f][0] << endl;
  }
}