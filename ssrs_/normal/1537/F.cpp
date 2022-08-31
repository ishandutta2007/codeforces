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
    vector<int> v(n);
    for (int j = 0; j < n; j++){
      cin >> v[j];
    }
    vector<int> t(n);
    for (int j = 0; j < n; j++){
      cin >> t[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int u, w;
      cin >> u >> w;
      u--;
      w--;
      E[u].push_back(w);
      E[w].push_back(u);
    }
    bool ok = true;
    vector<int> c(n, -1);
    for (int j = 0; j < n; j++){
      if (c[j] == -1){
        c[j] = 0;
        queue<int> Q;
        Q.push(j);
        vector<int> id;
        bool b = true;
        while (!Q.empty()){
          int u = Q.front();
          Q.pop();
          id.push_back(u);
          for (int w : E[u]){
            if (c[w] == -1){
              c[w] = 1 - c[u];
              Q.push(w);
            } else if (c[u] == c[w]){
              b = false;
            }
          }
        }
        long long V = 0, T = 0;
        for (int u : id){
          if (c[u] != 1){
            V += v[u];
            T += t[u];
          } else {
            V -= v[u];
            T -= t[u];
          }
        }
        if (!b){
          V %= 2;
          T %= 2;
          if (V < 0){
            V += 2;
          }
          if (T < 0){
            T += 2;
          }
        }
        if (V != T){
          ok = false;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}