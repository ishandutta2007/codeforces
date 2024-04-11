#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> c(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> c[i][j];
    }
  }
  vector<vector<int>> E(n * m);
  bool ok = true;
  for (int i = 1; i < n - 1; i++){
    for (int j = 1; j < m - 1; j++){
      if (c[i][j] == 'X'){
        vector<int> id;
        for (int k = 0; k < 4; k++){
          int x = i + dx[k];
          int y = j + dy[k];
          if (c[x][y] == '.'){
            id.push_back(x * m + y);
          }
        }
        int cnt = id.size();
        if (cnt % 2 != 0){
          ok = false;
        } else if (cnt == 2){
          E[id[0]].push_back(id[1]);
          E[id[1]].push_back(id[0]);
        } else if (cnt == 4){
          E[id[0]].push_back(id[1]);
          E[id[1]].push_back(id[0]);
          E[id[2]].push_back(id[3]);
          E[id[3]].push_back(id[2]);
        }
      }
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    vector<vector<int>> A(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (A[i][j] == -1 && c[i][j] == '.'){
          A[i][j] = 1;
          queue<pair<int, int>> Q;
          Q.push(make_pair(i, j));
          while (!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            int v = x * m + y;
            for (int w : E[v]){
              int x2 = w / m;
              int y2 = w % m;
              if (A[x2][y2] == -1){
                A[x2][y2] = 5 - A[x][y];
                Q.push(make_pair(x2, y2));
              }
            }
          }
        }
      }
    }
    for (int i = 1; i < n - 1; i++){
      for (int j = 1; j < m - 1; j++){
        if (c[i][j] == 'X'){
          A[i][j] = 0;
          for (int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if (c[x][y] == '.'){
              A[i][j] += A[x][y];
            }
          }
        }
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cout << A[i][j];
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}