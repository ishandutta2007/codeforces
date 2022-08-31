#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<string>> s(n, vector<string>(n));
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        cin >> s[j][k];
        s[k][j] = s[j][k];
      }
    }
    vector<vector<int>> E(n);
    for (int j = 1; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (s[j][k][0] == '1'){
          E[j].push_back(k);
          E[k].push_back(j);
        }
      }
    }
    vector<vector<int>> C;
    C.push_back(vector<int>(1, 0));
    vector<bool> used(n, false);
    for (int j = 1; j < n; j++){
      if (!used[j]){
        used[j] = true;
        queue<int> Q;
        Q.push(j);
        vector<int> tmp;
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          tmp.push_back(v);
          for (int w : E[v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
        C.push_back(tmp);
      }
    }
    int cnt = C.size();
    bool ok = false;
    for (int j = 1; j < cnt; j++){
      vector<int> p(n, -1);
      queue<int> Q2;
      for (int k : C[j]){
        p[k] = 0;
        Q2.push(k);
      }
      bool ok2 = true;
      while (!Q2.empty()){
        int v = Q2.front();
        Q2.pop();
        for (int k = 1; k < n; k++){
          if (k != p[v]){
            if (s[k][p[v]][v] == '1'){
              if (p[k] != -1){
                ok2 = false;
                break;
              } else {
                p[k] = v;
                Q2.push(k);
              }
            }
          }
        }
        if (!ok2){
          break;
        }
      }
      for (int k = 1; k < n; k++){
        if (p[k] == -1){
          ok2 = false;
        }
      }
      if (!ok2){
        continue;
      }
      vector<vector<int>> dist(n, vector<int>(n, n));
      for (int j = 0; j < n; j++){
        dist[j][j] = 0;
      }
      for (int j = 1; j < n; j++){
        dist[j][p[j]] = 1;
        dist[p[j]][j] = 1;
      }
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          for (int l = 0; l < n; l++){
            dist[k][l] = min(dist[k][l], dist[k][j] + dist[j][l]);
          }
        }
      }
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          for (int l = k + 1; l < n; l++){
            if (dist[j][k] == dist[j][l] && s[k][l][j] == '0'){
              ok2 = false;
            }
            if (dist[j][k] != dist[j][l] && s[k][l][j] == '1'){
              ok2 = false;
            }
          }
        }
      }
      if (!ok2){
        continue;
      }
      ok = true;
      cout << "Yes" << endl;
      for (int j = 1; j < n; j++){
        cout << p[j] + 1 << ' ' << j + 1 << endl;
      }
      break;
    }
    if (!ok){
      cout << "No" << endl;
    }
  }
}