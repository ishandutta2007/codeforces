#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> in(n);
    vector<vector<int>> E(n);
    for (int j = 0; j < n; j++){
      cin >> in[j];
      for (int k = 0; k < in[j]; k++){
        int a;
        cin >> a;
        a--;
        E[a].push_back(j);
      }
    }
    vector<int> dp(n, -1);
    queue<int> Q;
    for (int j = 0; j < n; j++){
      if (in[j] == 0){
        dp[j] = 1;
        Q.push(j);
      }
    }
    int cnt = 0;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      cnt++;
      for (int w : E[v]){
        if (w > v){
          dp[w] = max(dp[w], dp[v]);
        } else {
          dp[w] = max(dp[w], dp[v] + 1);
        }
        in[w]--;
        if (in[w] == 0){
          Q.push(w);
        }
      }
    }
    if (cnt < n){
      cout << -1 << endl;
    } else {
      int ans = 0;
      for (int j = 0; j < n; j++){
        ans = max(ans, dp[j]);
      }
      cout << ans << endl;
    }
  }
}