#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    E[a].push_back(make_pair(c, b));
  }
  for (int i = 0; i < n; i++){
    vector<int> t(n, INF);
    for (auto P : E[i]){
      int c = P.first;
      int b = P.second;
      for (int j = 0; j < n; j++){
        t[b] = min(t[b], c + j);
        b++;
        if (b == n){
          b = 0;
        }
      }
    }
    int mn = INF;
    for (int j = 0; j < n; j++){
      mn = min(mn, t[j]);
    }
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++){
      dp[t[j] - mn][j] = true;
    }
    vector<int> ans(n, -1);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (dp[j][k]){
          if (ans[k] == -1){
            ans[k] = mn + j;
            for (auto P : E[k]){
              int c = P.first;
              int v = P.second;
              if (j + c < n){
                int v2 = (v + mn + j) % n;
                dp[j + c][v2] = true;
              }
            }
          }
          if (j < n - 1){
            int k2 = (k + 1) % n;
            dp[j + 1][k] = true;
            dp[j + 1][k2] = true;
          }
        }
      }
    }
    ans[i] = 0;
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}