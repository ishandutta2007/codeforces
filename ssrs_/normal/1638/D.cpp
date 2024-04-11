#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  queue<pair<int, int>> Q;
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < m - 1; j++){
      if (a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1]){
        Q.push(make_pair(i, j));
      }
    }
  }
  vector<tuple<int, int, int>> ans;
  while (!Q.empty()){
    int x = Q.front().first;
    int y = Q.front().second;
    Q.pop();
    int c = -1;
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 2; j++){
        if (a[x + i][y + j] != -1){
          c = a[x + i][y + j];
        }
      }
    }
    if (c != -1){
      ans.push_back(make_tuple(x, y, c));
      a[x][y] = -1;
      a[x][y + 1] = -1;
      a[x + 1][y] = -1;
      a[x + 1][y + 1] = -1;
      for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
          int x2 = x + i;
          int y2 = y + j;
          if (0 <= x2 && x2 < n - 1 && 0 <= y2 && y2 < m - 1){
            int p = -1;
            bool ok = true;
            for (int k = 0; k < 2; k++){
              for (int l = 0; l < 2; l++){
                if (a[x2 + k][y2 + l] != -1){
                  if (p != -1 && a[x2 + k][y2 + l] != p){
                    ok = false;
                  } else {
                    p = a[x2 + k][y2 + l];
                  }
                }
              }
            }
            if (ok){
              Q.push(make_pair(x2, y2));
            }
          }
        }
      }
    }
  }
  if (a != vector<vector<int>>(n, vector<int>(m, -1))){
    cout << -1 << endl;
  } else {
    reverse(ans.begin(), ans.end());
    int k = ans.size();
    cout << k << endl;
    for (int i = 0; i < k; i++){
      cout << get<0>(ans[i]) + 1 << ' ' << get<1>(ans[i]) + 1 << ' ' << get<2>(ans[i]) << "\n";
    }
  }
}