#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E1(n), E2(n);
    for (int j = 0; j < m; j++){
      int t, x, y;
      cin >> t >> x >> y;
      x--;
      y--;
      if (t == 0){
        E2[x].push_back(y);
        E2[y].push_back(x);
      }
      if (t == 1){
        E1[x].push_back(y);
      }
    }
    vector<int> indeg(n, 0);
    for (int j = 0; j < n; j++){
      for (int v : E1[j]){
        indeg[v]++;
      }
    }
    queue<int> Q;
    for (int j = 0; j < n; j++){
      if (indeg[j] == 0){
        Q.push(j);
      }
    }
    vector<int> tsort;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      tsort.push_back(v);
      for (int w : E1[v]){
        indeg[w]--;
        if (indeg[w] == 0){
          Q.push(w);
        }
      }
    }
    if (tsort.size() < n){
      cout << "NO" << "\n";
    } else {
      vector<int> ord(n);
      for (int j = 0; j < n; j++){
        ord[tsort[j]] = j;
      }
      cout << "YES" << "\n";
      for (int j = 0; j < n; j++){
        for (int v : E1[j]){
          cout << j + 1 << ' ' << v + 1 << "\n";
        }
      }
      for (int j = 0; j < n; j++){
        for (int v : E2[j]){
          if (ord[j] < ord[v]){
            cout << j + 1 << ' ' << v + 1 << "\n";
          }
        }
      }
    }
  }
}