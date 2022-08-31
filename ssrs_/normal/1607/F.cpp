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
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<int> nxt(n * m);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        int j2 = j, k2 = k;
        if (s[j][k] == 'U'){
          j2--;
        }
        if (s[j][k] == 'D'){
          j2++;
        }
        if (s[j][k] == 'L'){
          k2--;
        }
        if (s[j][k] == 'R'){
          k2++;
        }
        if (0 <= j2 && j2 < n && 0 <= k2 && k2 < m){
          nxt[j * m + k] = j2 * m + k2;
        } else {
          nxt[j * m + k] = -1;
        }
      }
    }
    vector<vector<int>> P(n * m);
    for (int j = 0; j < n * m; j++){
      if (nxt[j] != -1){
        P[nxt[j]].push_back(j);
      }
    }
    vector<int> dp(n * m, -1);
    queue<int> Q;
    for (int j = 0; j < n * m; j++){
      if (nxt[j] == -1){
        dp[j] = 1;
        Q.push(j);
      }
    }
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : P[v]){
        dp[w] = dp[v] + 1;
        Q.push(w);
      }
    }
    vector<int> in(n * m);
    for (int j = 0; j < n * m; j++){
      in[j] = P[j].size();
    }
    vector<bool> cycle(n * m, true);
    for (int j = 0; j < n * m; j++){
      if (dp[j] != -1){
        cycle[j] = false;
      } else if (in[j] == 0){
        Q.push(j);
      }
    }
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      cycle[v] = false;
      in[nxt[v]]--;
      if (in[nxt[v]] == 0){
        Q.push(nxt[v]);
      }
    }
    for (int j = 0; j < n * m; j++){
      if (cycle[j] && dp[j] == -1){
        int v = j;
        int cnt = 0;
        while (true){
          v = nxt[v];
          cnt++;
          if (v == j){
            break;
          }
        }
        v = j;
        while (true){
          dp[v] = cnt;
          Q.push(v);
          while (!Q.empty()){
            int v2 = Q.front();
            Q.pop();
            for (int w : P[v2]){
              if (!cycle[w]){
                dp[w] = dp[v2] + 1;
                Q.push(w);
              }
            }
          }
          v = nxt[v];
          if (v == j){
            break;
          }
        }
      }
    }
    int r, c, d = -1;
    for (int j = 0; j < n * m; j++){
      if (dp[j] > d){
        r = j / m;
        c = j % m;
        d = dp[j];
      }
    }
    cout << r + 1 << ' ' << c + 1 << ' ' << d << endl;
  }
}