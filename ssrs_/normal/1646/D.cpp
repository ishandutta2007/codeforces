#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  if (n == 2){
    cout << 2 << ' ' << 2 << endl;
    cout << 1 << ' ' << 1 << endl;
  } else {
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
    vector<int> dp0c(n, 0), dp0s(n, 0);
    vector<int> dp1c(n, 1), dp1s(n, 0);
    vector<int> ch(n);
    for (int v : bfs){
      dp0s[v] = 1;
      dp1s[v] = E[v].size();
      for (int w : c[v]){
        dp0c[v] += max(dp0c[w], dp1c[w]);
        if (dp0c[w] > dp1c[w] || dp0c[w] == dp1c[w] && dp0s[w] < dp1s[w]){
          dp0s[v] += dp0s[w];
          ch[w] = 0;
        } else {
          dp0s[v] += dp1s[w];
          ch[w] = 1;
        }
        dp1c[v] += dp0c[w];
        dp1s[v] += dp0s[w];
      }
    }
    reverse(bfs.begin(), bfs.end());
    int cnt, sum;
    vector<bool> co(n);
    if (dp0c[0] > dp1c[0] || dp0c[0] == dp1c[0] && dp0s[0] < dp1s[0]){
      cnt = dp0c[0];
      sum = dp0s[0];
      co[0] = false;
    } else {
      cnt = dp1c[0];
      sum = dp1s[0];
      co[0] = true;
    }
    for (int v : bfs){
      if (!co[v]){
        for (int w : c[v]){
          co[w] = ch[w];
        }
      } else {
        for (int w : c[v]){
          co[w] = false;
        }
      }
    }
    vector<int> w(n, 1);
    for (int i = 0; i < n; i++){
      if (co[i]){
        w[i] = E[i].size();
      }
    }
    cout << cnt << ' ' << sum << endl;
    for (int i = 0; i < n; i++){
      cout << w[i];
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}