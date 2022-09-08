#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> E(n);
    for (int j = 0; j < m; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(make_pair(j, v));
      E[v].push_back(make_pair(j, u));
    }
    while (true){
      vector<int> c(m);
      for (int j = 0; j < m; j++){
        c[j] = mt() % 2;
      }
      bool ok = true;
      for (int j = 0; j < 2; j++){
        vector<bool> used(n, false);
        for (int k = 0; k < n; k++){
          if (!used[k]){
            used[k] = true;
            queue<int> Q;
            Q.push(k);
            int cntv = 0, cnte = 0;
            while (!Q.empty()){
              int v = Q.front();
              Q.pop();
              cntv++;
              for (auto P : E[v]){
                if (c[P.first] == j){
                  cnte++;
                  int w = P.second;
                  if (!used[w]){
                    used[w] = true;
                    Q.push(w);
                  }
                }
              }
            }
            if (cnte / 2 >= cntv){
              ok = false;
              break;
            }
          }
        }
      }
      if (ok){
        for (int j = 0; j < m; j++){
          cout << c[j];
        }
        cout << "\n";
        break;
      }
    }
  }
}