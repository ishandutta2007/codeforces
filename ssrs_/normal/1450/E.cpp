#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int k = 0; k < m; k++){
    int i, j, b;
    cin >> i >> j >> b;
    i--;
    j--;
    E[i].push_back(make_pair(j, b));
    E[j].push_back(make_pair(i, -b));
  }
  vector<int> c(n, -1);
  for (int i = 0; i < n; i++){
    if (c[i] == -1){
      c[i] = 0;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (auto P : E[v]){
          int w = P.first;
          if (c[v] == c[w]){
            cout << "NO" << endl;
            return 0;
          } else if (c[w] == -1){
            c[w] = 1 - c[v];
            Q.push(w);
          }
        }
      }
    }
  }
  vector<vector<int>> mn(n, vector<int>(n, -INF));
  vector<vector<int>> mx(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++){
    mn[i][i] = 0;
    mx[i][i] = 0;
  }
  for (int i = 0; i < n; i++){
    for (auto P : E[i]){
      int j = P.first;
      int b = P.second;
      if (b == 0){
        mn[i][j] = -1;
        mn[j][i] = -1;
        mx[i][j] = 1;
        mx[j][i] = 1;
      } else {
        mn[i][j] = -b;
        mn[j][i] = b;
        mx[i][j] = -b;
        mn[j][i] = b;
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        mn[j][k] = max(mn[j][k], mn[j][i] + mn[i][k]);
        mx[j][k] = min(mx[j][k], mx[j][i] + mx[i][k]);
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (mn[i][j] > mx[i][j]){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  int ma = 0;
  int mp = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (mx[i][j] > ma){
        ma = mx[i][j];
        mp = j;
      }
    }
  }
  cout << "YES" << endl;
  cout << ma << endl;
  for (int i = 0; i < n; i++){
    cout << 1000 + mx[i][mp];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}