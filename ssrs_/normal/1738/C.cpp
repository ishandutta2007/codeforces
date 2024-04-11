#include <bits/stdc++.h>
using namespace std;
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
    vector<int> c(2, 0);
    for (int j = 0; j < n; j++){
      c[abs(a[j]) % 2]++;
    }
    vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(c[0] + 1, vector<bool>(c[1] + 1, false)));
    dp[n % 2][0][0] = true;
    for (int j = 0; j <= c[0]; j++){
      for (int k = 0; k <= c[1]; k++){
        for (int l = 0; l < 2; l++){
          int p = (n - j - k) % 2;
          if (j > 0){
            if (!dp[l][j - 1][k]){
              dp[l][j][k] = true;
            }
          }
          if (k > 0){
            if (!dp[l ^ p ^ 1][j][k - 1]){
              dp[l][j][k] = true;
            }
          }
        }
      }
    }
    if (dp[0][c[0]][c[1]]){
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  }
}