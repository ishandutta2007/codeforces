#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<char>> c(n, vector<char>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c[i][j];
    }
  }
  int m = n * 2 - 1;
  vector<vector<char>> ans(m, vector<char>(m, 'x'));
  ans[n - 1][n - 1] = 'o';
  vector<pair<int, int>> vec;
  for (int dy = -n + 1; dy < n; dy++){
    for (int dx = -n + 1; dx < n; dx++){
      if (dy == 0 && dx == 0){
        continue;
      }
      bool atk = true;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          if (c[i][j] == 'o'){
            if (0 <= i + dy && i + dy < n && 0 <= j + dx && j + dx < n){
              int y = i + dy;
              int x = j + dx;
              if (c[y][x] == '.'){
                atk = false;
              }
            }
          }
        }
      }
      if (!atk){
        ans[dy + n - 1][dx + n - 1] = '.';
      } else {
        vec.push_back(make_pair(dy, dx));
      }
    }
  }
  vector<vector<char>> c2(n, vector<char>(n, '.'));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (c[i][j] == 'o'){
        c2[i][j] = 'o';
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (c[i][j] == 'o'){
        for (auto P : vec){
          int y = i + P.first;
          int x = j + P.second;
          if (0 <= y && y < n && 0 <= x && x < n){
            if (c2[y][x] == '.'){
              c2[y][x] = 'x';
            }
          }
        }
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (c[i][j] != c2[i][j]){
        ok = false;
      }
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < m; i++){
      for (int j = 0; j < m; j++){
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
}