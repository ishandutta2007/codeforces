#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<bool> used(n * n, false);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      used[a[i][j]] = true;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n * n; i++){
    if (used[i]){
      cnt++;
    }
  }
  if (k >= cnt){
    cout << k - cnt << endl;
  } else {
    vector<int> xmn(n * n, INF), xmx(n * n, -INF);
    vector<int> ymn(n * n, INF), ymx(n * n, -INF);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        xmn[a[i][j]] = min(xmn[a[i][j]], i);
        xmx[a[i][j]] = max(xmx[a[i][j]], i);
        ymn[a[i][j]] = min(ymn[a[i][j]], j);
        ymx[a[i][j]] = max(ymx[a[i][j]], j);
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++){
      vector<vector<int>> imos(n + 2, vector<int>(n + 2, 0));
      for (int j = 0; j < n * n; j++){
        if (used[j] && xmn[j] >= i){
          int Y = ymn[j] + xmx[j] - i + 1;
          if (Y >= n){
            imos[xmx[j]][ymx[j]]++;
            imos[xmx[j] + 1][ymx[j] + 1]--;
          } else if (Y > ymx[j]){
            imos[xmx[j]][ymx[j]]++;
            imos[xmx[j] + 1][ymx[j] + 1]--;
            imos[xmx[j]][Y]--;
            imos[xmx[j] + 1][Y]++;
          } else {
            int X = i + (ymx[j] - ymn[j]);
            if (X < n){
              imos[X][ymx[j]]++;
              imos[X][ymx[j] + 1]--;
            }
          }
        }
      }
      for (int j = 0; j < n + 2; j++){
        for (int l = 0; l < n + 1; l++){
          imos[j][l + 1] += imos[j][l];
        }
      }
      for (int j = 0; j < n + 1; j++){
        for (int l = 0; l < n + 2; l++){
          imos[j + 1][l] += imos[j][l];
        }
      }
      for (int j = 0; j < n + 1; j++){
        for (int l = 0; l < n + 1; l++){
          imos[j + 1][l + 1] += imos[j][l];
        }
      }
      for (int j = i; j < n; j++){
        for (int l = j - i; l < n; l++){
          if (cnt - imos[j][l] == k){
            ok = true;
          }
          if (cnt - imos[j][l] + 1 == k){
            ok = true;
          }
        }
      }
    }
    if (ok){
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}