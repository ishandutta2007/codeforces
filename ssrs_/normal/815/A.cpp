#include <bits/stdc++.h>
using namespace std;
int INF = 10000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  int min_g = INF;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> g[i][j];
      min_g = min(min_g, g[i][j]);
    }
  }
  int y, x;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      g[i][j] -= min_g;
      if (g[i][j] == 0){
        y = i;
        x = j;
      }
    }
  }
  vector<int> rcnt(n, 0);
  vector<int> ccnt(m, 0);
  for (int i = 0; i < n; i++){
    rcnt[i] = g[i][x];
  }
  for (int i = 0; i < m; i++){
    ccnt[i] = g[y][i];
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (g[i][j] != rcnt[i] + ccnt[j]){
        ok = false;
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    if (n < m){
      for (int i = 0; i < n; i++){
        rcnt[i] += min_g;
      }
    } else {
      for (int i = 0; i < m; i++){
        ccnt[i] += min_g;
      }
    }
    int k = 0;
    for (int i = 0; i < n; i++){
      k += rcnt[i];
    }
    for (int i = 0; i < m; i++){
      k += ccnt[i];
    }
    cout << k << endl;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < rcnt[i]; j++){
        cout << "row " << i + 1 << endl;
      }
    }
    for (int i = 0; i < m; i++){
      for (int j = 0; j < ccnt[i]; j++){
        cout << "col " << i + 1 << endl;
      }
    }
  }
}