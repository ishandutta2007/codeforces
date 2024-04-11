#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    vector<vector<pair<int, int>>> E(k * 2);
    for (int j = 0; j < k * 2 - 1; j++){
      int a, b, t;
      cin >> a >> b >> t;
      a--;
      b--;
      E[a].push_back(make_pair(t, b));
      E[b].push_back(make_pair(t, a));
    }
    vector<int> p(k * 2, -1);
    vector<vector<pair<int, int>>> c(k * 2);
    queue<int> Q;
    Q.push(0);
    vector<int> bfs;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      bfs.push_back(v);
      for (auto P : E[v]){
        int w = P.second;
        if (w != p[v]){
          p[w] = v;
          c[v].push_back(P);
          Q.push(w);
        }
      }
    }
    reverse(bfs.begin(), bfs.end());
    vector<int> dp(k * 2, 1);
    for (int v : bfs){
      for (auto P : c[v]){
        int w = P.second;
        dp[v] += dp[w];
      }
    }
    long long G = 0, B = 0;
    for (int v : bfs){
      for (auto P : c[v]){
        int w = P.second;
        if (dp[w] % 2 == 1){
          G += P.first;
        }
        B += (long long) min(dp[w], k * 2 - dp[w]) * P.first;
      }
    }
    cout << G << ' ' << B << endl;
  }
}