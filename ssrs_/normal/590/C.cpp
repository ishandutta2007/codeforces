#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> c(n + 2, vector<char>(m + 2, '#'));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> c[i][j];
    }
  }
  vector<vector<vector<int>>> d(3, vector<vector<int>>(n + 2, vector<int>(m + 2, INF)));
  for (int i = 0; i < 3; i++){
    queue<pair<int, int>> Q;
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        if (c[j][k] == '1' + i){
          d[i][j][k] = 0;
          Q.push(make_pair(j, k));
        }
      }
    }
    while (!Q.empty()){
      int y = Q.front().first;
      int x = Q.front().second;
      Q.pop();
      for (int j = 0; j < 4; j++){
        int y2 = y + dy[j];
        int x2 = x + dx[j];
        if (c[y2][x2] != '#' && d[i][y2][x2] == INF){
          if (c[y2][x2] == '.'){
            d[i][y2][x2] = d[i][y][x] + 1;
          } else {
            d[i][y2][x2] = d[i][y][x];
          }
          Q.push(make_pair(y2, x2));
        }
      }
    }
  }
  int d12 = INF, d23 = INF, d31 = INF;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (c[i][j] == '1'){
        d12 = min(d12, d[1][i][j]);
      }
      if (c[i][j] == '2'){
        d23 = min(d23, d[2][i][j]);
      }
      if (c[i][j] == '3'){
        d31 = min(d31, d[0][i][j]);
      }
    }
  }
  int ans = INF;
  ans = min(ans, d12 + d23);
  ans = min(ans, d23 + d31);
  ans = min(ans, d31 + d12);
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (c[i][j] == '.'){
        ans = min(ans, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);
      }
    }
  }
  if (ans > INF / 2){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}