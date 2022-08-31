#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
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
    vector<int> dp = a;
    for (int v : bfs){
      for (int w : c[v]){
        dp[v] ^= dp[w];
      }
    }
    if (dp[0] == 0){
      cout << "YES" << endl;
    } else {
      if (k == 2){
        cout << "NO" << endl;
      } else {
        vector<int> cnt(n, 0);
        for (int j = 0; j < n; j++){
          if (dp[j] == dp[0]){
            cnt[j]++;
          }
        }
        for (int v : bfs){
          for (int w : c[v]){
            cnt[v] += cnt[w];
          }
        }
        int cnt2 = 0;
        bool ok = false;
        for (int j = 0; j < n; j++){
          if (dp[j] == dp[0] && cnt[j] == 1){
            cnt2++;
          }
          if (dp[j] == 0 && cnt[j] >= 1){
            ok = true;
          }
        }
        if (cnt2 >= 2){
          ok = true;
        }
        if (ok){
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    }
  }
}