#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
    }
    vector<int> d(n, -1);
    d[0] = 0;
    queue<int> Q;
    Q.push(0);
    vector<int> b;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      b.push_back(v);
      for (int w : E[v]){
        if (d[w] == -1){
          d[w] = d[v] + 1;
          Q.push(w);
        }
      }
    }
    vector<vector<int>> E2(n * 2);
    for (int j = 0; j < n; j++){
      for (int k : E[j]){
        if (d[j] < d[k]){
          E2[k].push_back(j);
          E2[n + k].push_back(n + j);
        } else {
          E2[n + k].push_back(j);
        }
      }
    }
    vector<int> d2(n * 2, -1);
    for (int j : b){
      for (int k = 0; k < 2; k++){
        int id = j + k * n;
        if (d2[id] == -1){
          int dd = d[j];
          queue<int> Q2;
          Q2.push(id);
          d2[id] = dd;
          while (!Q2.empty()){
            int v = Q2.front();
            Q2.pop();
            for (int w : E2[v]){
              if (d2[w] == -1){
                d2[w] = dd;
                Q2.push(w);
              }
            }
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << d2[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}