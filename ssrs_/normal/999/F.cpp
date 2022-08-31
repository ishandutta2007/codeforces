#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> c(n * k);
  for (int i = 0; i < n * k; i++){
    cin >> c[i];
  }
  vector<int> f(n);
  for (int i = 0; i < n; i++){
    cin >> f[i];
  }
  vector<int> h(k + 1);
  h[0] = 0;
  for (int i = 1; i <= k; i++){
    cin >> h[i];
  }
  map<int, int> mp1;
  for (int i = 0; i < n * k; i++){
    mp1[c[i]]++;
  }
  map<int, int> mp2;
  for (int i = 0; i < n; i++){
    mp2[f[i]]++;
  }
  int ans = 0;
  for (auto P : mp2){
    int c1 = P.second;
    int c2 = mp1[P.first];
    vector<vector<int>> dp(c1 + 1, vector<int>(c2 + 1, 0));
    for (int i = 0; i < c1; i++){
      dp[i + 1] = dp[i];
      for (int j = 0; j <= c2; j++){
        for (int l = 0; l <= k; l++){
          if (j + l <= c2){
            dp[i + 1][j + l] = max(dp[i + 1][j + l], dp[i][j] + h[l]);
          }
        }
      }
    }
    ans += dp[c1][c2];
  }
  cout << ans << endl;
}