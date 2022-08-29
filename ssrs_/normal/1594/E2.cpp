#include <bits/stdc++.h>
using namespace std;
vector<string> color = {"white", "yellow", "green", "blue", "red", "orange"};
const long long MOD = 1000000007;
vector<long long> dfs(map<long long, int> &mp1, map<long long, int> &mp2, vector<vector<long long>> &dp, int k, int d, long long v = 1){
  if (mp2.count(v) == 0){
    return dp[k - 1 - d];
  } else if (d == k - 1){
    int id = mp1[v];
    vector<long long> ans(6, 0);
    ans[id] = 1;
    return ans;
  } else {
    vector<long long> L = dfs(mp1, mp2, dp, k, d + 1, v * 2);
    vector<long long> R = dfs(mp1, mp2, dp, k, d + 1, v * 2 + 1);
    int id = -1;
    if (mp1.count(v) == 1){
      id = mp1[v];
    }
    vector<long long> ans(6, 0);
    for (int i = 0; i < 6; i++){
      if (id == -1 || id == i){
        for (int j = 0; j < 6; j++){
          for (int k = 0; k < 6; k++){
            if (j != i && j != (i ^ 1) && k != i && k != (i ^ 1)){
              ans[i] += L[j] * R[k];
              ans[i] %= MOD;
            }
          }
        }
      }
    }
    return ans;
  }
}
int main(){
  int k;
  cin >> k;
  int n;
  cin >> n;
  vector<long long> v(n);
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> v[i] >> s[i];
  }
  map<long long, int> mp1;
  for (int i = 0; i < n; i++){
    int id;
    for (int j = 0; j < 6; j++){
      if (s[i] == color[j]){
        id = j;
      }
    }
    mp1[v[i]] = id;
  }
  map<long long, int> mp2;
  for (int i = 0; i < n; i++){
    long long x = v[i];
    while (x > 0){
      mp2[x]++;
      x /= 2;
    } 
  }
  vector<vector<long long>> dp(k, vector<long long>(6, 0));
  for (int i = 0; i < 6; i++){
    dp[0][i] = 1;
  }
  for (int i = 0; i < k - 1; i++){
    for (int j = 0; j < 6; j++){
      for (int l = 0; l < 6; l++){
        for (int m = 0; m < 6; m++){
          if (j != m && j != (m ^ 1) && l != m && l != (m ^ 1)){
            dp[i + 1][m] += dp[i][j] * dp[i][l];
            dp[i + 1][m] %= MOD;
          }
        }
      }
    }
  }
  vector<long long> res = dfs(mp1, mp2, dp, k, 0);
  long long ans = 0;
  for (int i = 0; i < 6; i++){
    ans += res[i];
  }
  ans %= MOD;
  cout << ans << endl;
}