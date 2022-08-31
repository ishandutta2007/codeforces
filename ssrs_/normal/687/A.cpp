#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> c(n, -1);
  bool ok = true;
  for (int i = 0; i < n; i++){
    if (c[i] == -1){
      c[i] = i % 2;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (c[w] == -1){
            c[w] = 1 - c[v];
            Q.push(w);
          } else if (c[w] == c[v]){
            ok = false;
          }
        }
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    vector<vector<int>> A(2);
    for (int i = 0; i < n; i++){
      A[c[i]].push_back(i);
    }
    for (int i = 0; i < 2; i++){
      int sz = A[i].size();
      cout << sz << endl;
      for (int j = 0; j < sz; j++){
        cout << A[i][j] + 1;
        if (j < sz - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}