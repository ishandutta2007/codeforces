#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> c[j][k];
      }
    }
    int sx, sy;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (c[j][k] == 'L'){
          sx = j;
          sy = k;
        }
      }
    }
    queue<pair<int, int>> Q;
    Q.push(make_pair(sx, sy));
    while (!Q.empty()){
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop();
      for (int j = 0; j < 4; j++){
        int x2 = x + dx[j];
        int y2 = y + dy[j];
        if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m){
          if (c[x2][y2] == '.'){
            int cnt = 0;
            for (int k = 0; k < 4; k++){
              int x3 = x2 + dx[k];
              int y3 = y2 + dy[k];
              if (0 <= x3 && x3 < n && 0 <= y3 && y3 < m){
                if (c[x3][y3] == '.'){
                  cnt++;
                }
              }
            }
            if (cnt <= 1){
              c[x2][y2] = '+';
              Q.push(make_pair(x2, y2));
            }
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cout << c[j][k];
      }
      cout << "\n";
    }
  }
}