#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int n;
  cin >> n;
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  vector<string> s(4);
  for (int i = 0; i < 4; i++){
    cin >> s[i];
  }
  vector<int> dp(1 << 15, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 4; j++){
      vector<int> dp2(1 << 15, INF);
      for (int k = 0; k < (1 << 15); k++){
        if (dp[k] != INF){
          int k2 = k * 2;
          if (s[j][i] == '*'){
            k2++;
          }
          if (k2 < (1 << 15)){
            dp2[k2] = min(dp2[k2], dp[k]);
            if (j >= 0){
              int k3 = k2 & ~(0b1);
              dp2[k3] = min(dp2[k3], dp[k] + a1);
            }
            if (j >= 1){
              int k3 = k2 & ~(0b110011);
              dp2[k3] = min(dp2[k3], dp[k] + a2);
            }
            if (j >= 2){
              int k3 = k2 & ~(0b11101110111);
              dp2[k3] = min(dp2[k3], dp[k] + a3);
            }
          }
          if (j == 3){
            dp2[0] = min(dp2[0], dp[k] + a4);
          }
        }
      }
      swap(dp, dp2);
    }
  }
  cout << dp[0] << endl;
}