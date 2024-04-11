#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &E, int s){
  int N = E.size();
  vector<int> d(N, -1);
  d[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (d[w] == -1){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  return d;
}
int main(){
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
  vector<int> d1 = bfs(E, 0);
  int s = max_element(d1.begin(), d1.end()) - d1.begin();
  vector<int> d2 = bfs(E, s);
  int t = max_element(d2.begin(), d2.end()) - d2.begin();
  vector<int> d3 = bfs(E, t);
  int d = d2[t];
  bool ok = true;
  vector<int> L;
  for (int i = 0; i < n; i++){
    if (E[i].size() == 1){
      if (d2[i] < d && d3[i] < d && d2[i] != d3[i]){
        ok = false;
      }
      if (d2[i] < d && d3[i] < d && d2[i] == d3[i]){
        L.push_back(d2[i]);
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else if (L.empty()){
    while (d % 2 == 0){
      d /= 2;
    }
    cout << d << endl;
  } else {
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    if (L.size() >= 2){
      cout << -1 << endl;
    } else {
      int r;
      for (int i = 0; i < n; i++){
        if (d2[i] == d / 2 && d3[i] == d / 2){
          r = i;
        }
      }
      vector<int> p(n, -1);
      vector<vector<int>> c(n);
      queue<int> Q;
      Q.push(r);
      vector<int> b;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        b.push_back(v);
        for (int w : E[v]){
          if (w != p[v]){
            p[w] = v;
            c[v].push_back(w);
            Q.push(w);
          }
        }
      }
      reverse(b.begin(), b.end());
      vector<int> d4 = bfs(E, r);
      vector<int> dp(n, 0);
      for (int v : b){
        if (c[v].empty()){
          if (d4[v] == d / 2){
            dp[v] = 1;
          } else {
            dp[v] = 2;
          }
        }
        for (int w : c[v]){
          dp[v] |= dp[w];
        }
      }
      for (int i = 0; i < n; i++){
        if (i != r && dp[i] == 3){
          ok = false;
        }
      }
      if (!ok){
        cout << -1 << endl;
      } else {
        int ans = L[0];
        while (ans % 2 == 0){
          ans /= 2;
        }
        cout << ans << endl;
      }
    }
  }
}