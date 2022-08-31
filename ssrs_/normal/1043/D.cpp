#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m, vector<int>(n));
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<vector<int>> p(m, vector<int>(n));
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      p[i][a[i][j]] = j;
    }
  }
  
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int v = a[0][i];
    int w = a[0][i + 1];
    bool ok = true;
    for (int j = 1; j < m; j++){
      if (p[j][v] + 1 != p[j][w]){
        ok = false;
      }
    }
    if (ok){
      E[v].push_back(w);
      E[w].push_back(v);
    }
  }
  long long ans = 0;
  vector<int> used(n, false);
  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      long long cnt = 1;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            cnt++;
            Q.push(w);
          }
        }
      }
      ans += cnt * (cnt + 1) / 2;
    }
  }
  cout << ans << endl;
}