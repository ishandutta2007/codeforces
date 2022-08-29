#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  int tv = 1000000001, fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    vector<vector<int>> E2(n);
    int cnt = 0;
    for (int i = 0; i < n; i++){
      if (a[i] <= mid){
        cnt++;
        for (int j : E[i]){
          if (a[j] <= mid){
            E2[i].push_back(j);
          }
        }
      }
    }
    if (cnt == 0){
      fv = mid;
    } else {
      vector<int> in(n, 0);
      for (int i = 0; i < n; i++){
        for (int j : E2[i]){
          in[j]++;
        }
      }
      queue<int> Q;
      for (int i = 0; i < n; i++){
        if (a[i] <= mid && in[i] == 0){
          Q.push(i);
        }
      }
      vector<int> T;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        T.push_back(v);
        for (int w : E2[v]){
          in[w]--;
          if (in[w] == 0){
            Q.push(w);
          }
        }
      }
      if (T.size() < cnt){
        tv = mid;
      } else {
        reverse(T.begin(), T.end());
        vector<int> dp(n, 0);
        int ans = 0;
        for (int v : T){
          dp[v] = 1;
          for (int w : E2[v]){
            dp[v] = max(dp[v], dp[w] + 1);
          }
          ans = max(ans, dp[v]);
        }
        if (ans >= k){
          tv = mid;
        } else {
          fv = mid;
        }
      }
    }
  }
  if (tv == 1000000001){
    cout << -1 << endl;
  } else {
    cout << tv << endl;
  }
}