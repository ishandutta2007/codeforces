#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n + 2, vector<char>(m + 2, '#'));
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        cin >> c[j][k];
      }
    }
    bool ok = true;
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        if (c[j][k] == 'B'){
          for (int d = 0; d < 4; d++){
            if (c[j + dy[d]][k + dx[d]] == 'G'){
              ok = false;
            } else if (c[j + dy[d]][k + dx[d]] == '.'){
              c[j + dy[d]][k + dx[d]] = '#';
            }
          }
        }
      }
    }
    vector<vector<bool>> used(n + 2, vector<bool>(m + 2, false));
    if (c[n][m] != '#'){
      used[n][m] = true;
      queue<pair<int, int>> Q;
      Q.push(make_pair(n, m));
      while (!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        for (int d = 0; d < 4; d++){
          int y2 = y + dy[d];
          int x2 = x + dx[d];
          if (c[y2][x2] != '#' && !used[y2][x2]){
            used[y2][x2] = true;
            Q.push(make_pair(y2, x2));
          }
        }
      }
    }
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        if (c[j][k] == 'G' && !used[j][k]){
          ok = false;
        }
      }
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}