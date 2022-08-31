#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> s(n + 1, vector<char>(m + 1, 'W'));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> s[i][j];
    }
  }
  vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= m; j++){
      int cnt = 0;
      if (s[i][j] == 'B'){
        cnt++;
      }
      if (i < n){
        if (s[i + 1][j] == 'B'){
          cnt++;
        }
      }
      if (j < m){
        if (s[i][j + 1] == 'B'){
          cnt++;
        }
      }
      if (i < n && j < m){
        if (s[i + 1][j + 1] == 'B'){
          cnt++;
        }
      }
      a[i][j] = cnt % 2;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (a[i][j] == 1){
        cnt++;
      }
    }
  }
  int ans = cnt;
  if (a[n][m] == 1){
    for (int i = 1; i < n; i++){
      for (int j = 1; j < m; j++){
        if (a[i][j] == 1 && a[i][m] == 1 && a[n][j] == 1){
          ans = cnt - 1;
        }
      }
    }
  }
  cout << ans << endl;
}