#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, t;
  cin >> n >> m >> t;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      char c;
      cin >> c;
      A[i][j] = c - '0';
    }
  }
  vector<vector<int>> s(n, vector<int>(m, -1));
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      bool same = false;
      for (int k = 0; k < 4; k++){
        int y = i + dy[k];
        int x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m){
          if (A[y][x] == A[i][j]){
            same = true;
          }
        }
      }
      if (same){
        s[i][j] = 1;
        Q.push(make_pair(i, j));
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
      if (0 <= y2 && y2 < n && 0 <= x2 && x2 < m){
        if (s[y2][x2] == -1){
          s[y2][x2] = s[y][x] + 1;
          Q.push(make_pair(y2, x2));
        }
      }
    }
  }
  /*
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << s[i][j] << ' ';
    }
    cout << endl;
  }
  */
  for (int i = 0; i < t; i++){
    int y, x;
    long long p;
    cin >> y >> x >> p;
    y--;
    x--;
    if (s[y][x] == -1){
      cout << A[y][x] << endl;
    } else if (p < s[y][x]){
      cout << A[y][x] << endl;
    } else if ((p - s[y][x]) % 2 == 1){
      cout << A[y][x] << endl;
    } else {
      cout << 1 - A[y][x] << endl;
    }
  }
}