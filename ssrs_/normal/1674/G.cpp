#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  vector<int> in(n, 0);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      in[j]++;
    }
  }
  vector<int> in2 = in;
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (in[i] == 0){
      Q.push(i);
    }
  }
  vector<int> T;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    T.push_back(v);
    for (int w : E[v]){
      in[w]--;
      if (in[w] == 0){
        Q.push(w);
      }
    }
  }
  vector<int> dp(n, -INF);
  int ans = 1;
  for (int v : T){
    if (E[v].size() != 1){
      dp[v] = max(dp[v], 1);
    }
    for (int w : E[v]){
      if (in2[w] != 1 && E[w].size() != 1){
        dp[w] = max(dp[w], dp[v] + 1);
      }
      if (in2[w] != 1){
        ans = max(ans, dp[v] + 1);
      }
    }
  }
  cout << ans << endl;
}