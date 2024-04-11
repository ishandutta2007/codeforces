#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i][j] == 'X'){
        sum[i + 1][j + 1]++;
      }
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      sum[i][j] += sum[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      sum[i][j] += sum[i][j - 1];
    }
  }
  int tv = -1;
  int fv = 501;
  vector<vector<char>> ans;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    vector<vector<char>> tmp(n, vector<char>(m, '.'));
    for (int i = mid; i < n - mid; i++){
      for (int j = mid; j < m - mid; j++){
        int c = sum[i + mid + 1][j + mid + 1] - sum[i + mid + 1][j - mid] - sum[i - mid][j + mid + 1] + sum[i - mid][j - mid];
        if (c == (mid * 2 + 1) * (mid * 2 + 1)){
          tmp[i][j] = 'X';
        }
      }
    }
    vector<vector<int>> sum2(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (tmp[i][j] == 'X'){
          sum2[i + 1][j + 1]++;
        }
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        sum2[i][j] += sum2[i - 1][j];
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        sum2[i][j] += sum2[i][j - 1];
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (a[i][j] == 'X'){
          int ymin = max(i - mid, 0);
          int ymax = min(i + mid + 1, n);
          int xmin = max(j - mid, 0);
          int xmax = min(j + mid + 1, m);
          if (sum2[ymax][xmax] - sum2[ymax][xmin] - sum2[ymin][xmax] + sum2[ymin][xmin] == 0){
            ok = false;
            break;
          }
        }
        if (!ok){
          break;
        }
      }
    }
    if (ok){
      tv = mid;
      ans = tmp;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << ans[i][j];
    }
    cout << "\n";
  }
}