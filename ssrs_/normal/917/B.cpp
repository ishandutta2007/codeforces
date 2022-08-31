#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int v, u;
    char c;
    cin >> v >> u >> c;
    v--;
    u--;
    E[v].push_back(make_pair(c - 'a', u));
  }
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    for (auto P : E[i]){
      int w = P.second;
      d[w]++;
    }
  }
  vector<int> T;
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (d[i] == 0){
      Q.push(i);
    }
  }
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    T.push_back(v);
    for (auto P : E[v]){
      int w = P.second;
      d[w]--;
      if (d[w] == 0){
        Q.push(w);
      }
    }
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++){
    pos[T[i]] = i;
  }
  vector<pair<int, int>> P;
  vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(26, false)));
  for (int s = n * 2 - 2; s >= 0; s--){
    for (int i = n - 1; i >= 0; i--){
      int j = s - i;
      if (0 <= j && j < n){
        int v = T[i];
        for (int k = 0; k < 26; k++){
          for (auto P : E[v]){
            int c = P.first;
            int w = P.second;
            if (c >= k && !dp[j][pos[w]][c]){
              dp[i][j][k] = true;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (dp[pos[i]][pos[j]][0]){
        cout << 'A';
      } else {
        cout << 'B';
      }
    }
    cout << endl;
  }
}