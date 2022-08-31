#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  if (x >= y){
    long long ans = (long long) (n - 1) * y;
    bool star = false;
    for (int i = 0; i < n; i++){
      if (E[i].size() == n - 1){
        star = true;
      }
    }
    if (star){
      ans -= y;
      ans += x;
    }
    cout << ans << endl;
  } else {
    vector<int> p(n, -1);
    vector<vector<int>> c(n);
    vector<int> bfs;
    queue<int> Q;
    Q.push(0);
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
    vector<int> dp0(n, 0), dp1(n, 0);
    for (int v : bfs){
      int cnt = c[v].size();
      vector<vector<int>> dp2(3, vector<int>(cnt + 1, 0));
      for (int i = 0; i < cnt; i++){
        int w = c[v][i];
        for (int j = 0; j < 3; j++){
          dp2[j][i + 1] = max(dp2[j][i + 1], dp2[j][i] + dp0[w]);
          if (j < 2){
            dp2[j + 1][i + 1] = max(dp2[j + 1][i + 1], dp2[j][i] + dp1[w] + 1);
          }
        }
      }
      dp0[v] = dp2[2][cnt];
      dp1[v] = dp2[1][cnt];
    }
    cout << (long long) (n - 1) * y - (long long) (y - x) * dp0[0] << endl;
  }
}