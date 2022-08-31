#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> c(n + 2, vector<char>(m + 2, '.'));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> c[i][j];
    }
  }
  bool flg = true;
  bool h_none = false;
  for (int i = 1; i <= n; i++){
    int count = 0;
    for (int j = 1; j <= m + 1; j++){
      if (c[i][j - 1] != c[i][j]){
        count++;
      }
    }
    if (count > 2){
      flg = false;
    }
    if (count == 0){
      h_none = true;
    }
  }
  bool v_none = false;
  for (int i = 1; i <= m; i++){
    int count = 0;
    for (int j = 1; j <= n + 1; j++){
      if (c[j - 1][i] != c[j][i]){
        count++;
      }
    }
    if (count > 2){
      flg = false;
    }
    if (count == 0){
      v_none = true;
    }
  }
  if (!flg){
    cout << -1 << endl;
  } else if (h_none ^ v_none){
    cout << -1 << endl;
  } else {
    int ans = 0;
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        if (c[i][j] == '#'){ 
          ans++;
          c[i][j] = '.';
          queue<pair<int, int>> Q;
          Q.push(make_pair(i, j));
          while (!Q.empty()){
            int y = Q.front().first;
            int x = Q.front().second;
            Q.pop();
            for (int k = 0; k < 4; k++){
              if (c[y + dy[k]][x + dx[k]] == '#'){
                c[y + dy[k]][x + dx[k]] = '.';
                Q.push(make_pair(y + dy[k], x + dx[k]));
              }
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}