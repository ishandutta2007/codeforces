#include <bits/stdc++.h>
using namespace std;
const int MAX = 780;
const int INF = 10000000;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> r(k), c(k);
  for (int i = 0; i < k; i++){
    cin >> r[i] >> c[i];
    r[i]--;
    c[i]--;
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < k; i++){
    id[c[i]].push_back(i);
  }
  vector<int> dp(MAX, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    vector<int> dp2(MAX, INF);
    int mn = INF;
    for (int j = 0; j < MAX; j++){
      mn = min(mn, dp[j]);
      dp2[j] = mn + j * (j + 1) / 2 + 2;
      if (j < MAX - 1){
        dp2[j] = min(dp2[j], dp[j + 1]);
      }
      if (j == 0){
        dp2[j] = min(dp2[j], dp[j]);
      }
    }
    for (int j : id[i]){
      int p = n - r[j];
      for (int k = 0; k < min(p, MAX); k++){
        dp2[k] += 3;
      }
    }
    swap(dp, dp2);
  }
  int ans = INF;
  for (int i = 0; i < MAX; i++){
    ans = min(ans, dp[i]);
  }
  cout << ans << endl;
}