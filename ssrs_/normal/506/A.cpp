#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main(){
  int n, d;
  cin >> n >> d;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<int> g(30001, 0);
  for (int i = 0; i < n; i++){
    g[p[i]]++;
  }
  vector<unordered_map<int, int>> dp(30001);
  dp[d][d] = g[d];
  int ans = g[d];
  vector<int> ml(30001, INF);
  ml[d] = d;
  for (int i = d; i < 30000; i++){
    if (!dp[i].empty()){
      bool ok = false;
      if (ml[i] <= 3 && dp[i][ml[i]] == ans){
        ok = true;
      }
      for (auto P : dp[i]){
        int l = P.first;
        int cnt = P.second;
        if (ok && l > 3){
          continue;
        }
        for (int dl = -1; dl <= 1; dl++){
          int l2 = l + dl;
          int x = i + l2;
          if (x > i && x <= 30000){
            ans = max(ans, cnt + g[x]);
            ml[x] = min(ml[x], l2);
            dp[x][l2] = max(dp[x][l2], cnt + g[x]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}