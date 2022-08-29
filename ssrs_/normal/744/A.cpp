#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(k);
  for (int i = 0; i < k; i++){
    cin >> c[i];
    c[i]--;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> comp(n, -1);
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (comp[i] == -1){
      comp[i] = cnt;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (comp[w] == -1){
            comp[w] = cnt;
            Q.push(w);
          }
        }
      }
      cnt++;
    }
  }
  vector<bool> g(cnt, false);
  for (int i = 0; i < k; i++){
    g[comp[c[i]]] = true;
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      if (comp[i] == comp[j] || !g[comp[i]] && !g[comp[j]]){
        ans++;
      }
    }
  }
  vector<int> c_sz(cnt, 0);
  for (int i = 0; i < n; i++){
    c_sz[comp[i]]++;
  }
  int mx = 0;
  for (int i = 0; i < k; i++){
    mx = max(mx, c_sz[comp[c[i]]]);
  }
  int cnt2 = 0;
  for (int i = 0; i < n; i++){
    if (!g[comp[i]]){
      cnt2++;
    }
  }
  ans += mx * cnt2;
  ans -= m;
  cout << ans << endl;
}