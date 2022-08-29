#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> w(n);
    for (int j = 0; j < n; j++){
      cin >> w[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      E[x].push_back(y);
      E[y].push_back(x);
    }
    vector<int> p(n, -1);
    vector<vector<int>> c(n);
    queue<int> Q;
    Q.push(0);
    vector<int> bfs;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      bfs.push_back(v);
      for (int w : E[v]){
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(w);
          Q.push(w);
        }
      }
    }
    reverse(bfs.begin(), bfs.end());
    vector<vector<pair<int, long long>>> dp(n);
    for (int v : bfs){
      dp[v].push_back(make_pair(0, w[v] - b[v]));
      for (int w : c[v]){
        int cnt1 = dp[v].size();
        int cnt2 = dp[w].size();
        vector<pair<int, long long>> dp2(cnt1 + cnt2 - 1, make_pair(-1, -1));
        for (int j = 0; j < cnt1; j++){
          for (int k = 0; k < cnt2; k++){
            pair<int, long long> P = make_pair(dp[v][j].first + dp[w][k].first, dp[v][j].second + dp[w][k].second);
            dp2[j + k] = max(dp2[j + k], P);
          }
        }
        swap(dp[v], dp2);
      }
      int cnt = dp[v].size();
      if (v != 0){
        vector<pair<int, long long>> dp2(cnt + 1, make_pair(-1, -1));
        for (int j = 0; j < cnt; j++){
          dp2[j] = max(dp2[j], dp[v][j]);
          if (dp[v][j].second <= 0){
            dp2[j + 1] = max(dp2[j + 1], make_pair(dp[v][j].first, (long long) 0));
          } else {
            dp2[j + 1] = max(dp2[j + 1], make_pair(dp[v][j].first + 1, (long long) 0));
          }
        }
        swap(dp[v], dp2);
      }
    }
    int ans = dp[0][m - 1].first;
    if (dp[0][m - 1].second > 0){
      ans++;
    }
    cout << ans << endl;
  }
}