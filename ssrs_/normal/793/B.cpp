#include <bits/stdc++.h>
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> A(n + 2, vector<char>(m + 2, '*'));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> A[i][j];
    }
  }
  int sy, sx;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (A[i][j] == 'S'){
        sy = i;
        sx = j;
      }
    }
  }
  A[sy][sx] = '.';
  int ty, tx;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (A[i][j] == 'T'){
        ty = i;
        tx = j;
      }
    }
  }
  A[ty][tx] = '.';
  vector<vector<vector<int>>> t(n + 2, vector<vector<int>>(m + 2, vector<int>(4, -1)));
  deque<pair<int, tuple<int, int, int>>> dq;
  for (int i = 0; i < 4; i++){
    dq.push_back(make_pair(0, make_tuple(sy, sx, i)));
  }
  while (!dq.empty()){
    int c = dq.front().first;
    int y = get<0>(dq.front().second);
    int x = get<1>(dq.front().second);
    int d = get<2>(dq.front().second);
    dq.pop_front();
    if (t[y][x][d] == -1){
      t[y][x][d] = c;
      int y2 = y + dy[d];
      int x2 = x + dx[d];
      if (A[y2][x2] == '.' && t[y2][x2][d] == -1){
        dq.push_front(make_pair(c, make_tuple(y2, x2, d)));
      }
      if (c < 2){
        for (int i = 0; i < 4; i++){
          if (i != d && t[y2][x2][i] == -1){
            dq.push_back(make_pair(c + 1, make_tuple(y, x, i)));
          }
        }
      }
    }
  }
  bool ok = false;
  for (int i = 0; i < 4; i++){
    if (t[ty][tx][i] != -1){
      ok = true;
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}