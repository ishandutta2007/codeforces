#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> E(n, vector<bool>(n, false));
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u][v] = true;
    E[v][u] = true;
  }
  bool ok = true;
  vector<char> ans(n, 'x');
  for (int i = 0; i < n; i++){
    bool all = true;
    for (int j = 0; j < n; j++){
      if (i != j && !E[i][j]){
        all = false;
      }
    }
    if (all){
      ans[i] = 'b';
    }
  }
  for (int i = 0; i < n; i++){
    if (ans[i] == 'x'){
      ans[i] = 'a';
      for (int j = 0; j < n; j++){
        if (i != j && E[i][j] && ans[j] == 'c'){
          ans[i] = 'c';
        }
      }
      if (ans[i] == 'c'){
        for (int j = 0; j < n; j++){
          if (i != j && E[i][j] && ans[j] == 'a'){
            ok = false;
            break;
          }
        }
      }
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w = 0; w < n; w++){
          if (v == w){
            continue;
          }
          if (!E[v][w]){
            if (ans[w] == 'x'){
              if (ans[v] == 'a'){
                ans[w] = 'c';
              }
              if (ans[v] == 'c'){
                ans[w] = 'a';
              }
              Q.push(w);
            } else if (ans[v] == ans[w]){
              ok = false;
              break;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      bool tmp = (ans[i] == 'a' && ans[j] == 'c') || (ans[i] == 'c' && ans[j] == 'a');
      if (E[i][j] && tmp){
        ok = false;
      }
      if (!E[i][j] && !tmp){
        ok = false;
      }
    }
  }
  if (!ok){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++){
      cout << ans[i];
    }
    cout << endl;
  }
}