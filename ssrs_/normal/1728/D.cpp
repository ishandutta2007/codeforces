#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    for (int j = 0; j <= N; j++){
      dp[j][j] = 0;
    }
    for (int j = N - 2; j >= 0; j--){
      for (int k = j + 2; k <= N; k += 2){
        int ll = dp[j + 2][k];
        if (ll == 0){
          if (s[j] < s[j + 1]){
            ll = 1;
          }
          if (s[j] > s[j + 1]){
            ll = -1;
          }
        }
        int lr = dp[j + 1][k - 1];
        if (lr == 0){
          if (s[j] < s[k - 1]){
            lr = 1;
          }
          if (s[j] > s[k - 1]){
            lr = -1;
          }
        }
        int rl = dp[j + 1][k - 1];
        if (rl == 0){
          if (s[k - 1] < s[j]){
            rl = 1;
          }
          if (s[k - 1] > s[j]){
            rl = -1;
          }
        }
        int rr = dp[j][k - 2];
        if (rr == 0){
          if (s[k - 1] < s[k - 2]){
            rr = 1;
          }
          if (s[k - 1] > s[k - 2]){
            rr = -1;
          }
        }
        dp[j][k] = max(min(ll, lr), min(rl, rr));
      }
    }
    if (dp[0][N] == 1){
      cout << "Alice" << endl;
    } else if (dp[0][N] == -1){
      cout << "Bob" << endl;
    } else {
      cout << "Draw" << endl;
    }
  }
}