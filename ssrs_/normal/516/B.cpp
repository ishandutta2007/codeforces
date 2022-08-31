#include <bits/stdc++.h>
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
vector<char> tile = {'^', '<', 'v', '>'};
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> S(n + 2, vector<char>(m + 2, '*'));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> S[i][j];
    }
  }
  vector<vector<int>> cnt(n + 2, vector<int>(m + 2, 0));
  int t = 0;
  queue<pair<int, int>> Q;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (S[i][j] == '.'){
        t++;
        for (int k = 0; k < 4; k++){
          if (S[i + dy[k]][j + dx[k]] == '.'){
            cnt[i][j]++;
          }
        }
        if (cnt[i][j] == 1){
          Q.push(make_pair(i, j));
        }
      }
    }
  }
  while (!Q.empty()){
    int y = Q.front().first;
    int x = Q.front().second;
    Q.pop();
    for (int i = 0; i < 4; i++){
      int y2 = y + dy[i];
      int x2 = x + dx[i];
      if (S[y2][x2] == '.'){
        S[y][x] = tile[i];
        S[y2][x2] = tile[i ^ 2];
        t -= 2;
        for (int j = 0; j < 4; j++){
          int y3 = y2 + dy[j];
          int x3 = x2 + dx[j];
          if (S[y3][x3] == '.'){
            cnt[y3][x3]--;
            if (cnt[y3][x3] == 1){
              Q.push(make_pair(y3, x3));
            }
          }
        }
      }
    }
  }
  if (t != 0){
    cout << "Not unique" << endl;
  } else {
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        cout << S[i][j];
      }
      cout << endl;
    }
  }
}