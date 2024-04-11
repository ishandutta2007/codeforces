#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int k = 0; k < m; k++){
    int type, i, j;
    cin >> type >> i >> j;
    i--;
    j--;
    E[i].push_back(make_pair(type, j));
    E[j].push_back(make_pair(type, i));
  }
  vector<int> T(n, -1);
  bool ok = true;
  vector<vector<int>> E2(n);
  for (int i = 0; i < n; i++){
    if (T[i] == -1){
      T[i] = 0;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (auto P : E[v]){
          int w = P.second;
          if (T[w] == -1){
            T[w] = 1 - T[v];
            Q.push(w);
          }
          if (T[v] == T[w]){
            ok = false;
          } else {
            if (T[v] == 0){
              if (P.first == 1){
                E2[v].push_back(w);
              } else {
                E2[w].push_back(v);
              }
            } else {
              if (P.first == 1){
                E2[w].push_back(v);
              } else {
                E2[v].push_back(w);
              }
            }
          }
        }
      }
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    vector<int> d(n, 0);
    for (int i = 0; i < n; i++){
      for (int j : E2[i]){
        d[j]++;
      }
    }
    queue<int> Q;
    for (int i = 0; i < n; i++){
      if (d[i] == 0){
        Q.push(i);
      }
    }
    vector<int> t;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      t.push_back(v);
      for (int w : E2[v]){
        d[w]--;
        if (d[w] == 0){
          Q.push(w);
        }
      }
    }
    if (t.size() < n){
      cout << "NO" << endl;
    } else {
      vector<int> x(n);
      for (int i = 0; i < n; i++){
        x[t[i]] = i;
      }
      cout << "YES" << endl;
      for (int i = 0; i < n; i++){
        if (T[i] == 0){
          cout << "L ";
        } else {
          cout << "R ";
        }
        cout << x[i] << "\n";
      }
    }
  }
}