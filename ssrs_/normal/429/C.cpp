#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if (n == 1){
    cout << "YES" << endl;
    return 0;
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
    if (c[i] == 2){
      cout << "NO" << endl;
      return 0;
    }
  }
  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < n; i++){
    cnt[c[i]]++;
  }
  vector<int> d;
  for (int i = 0; i < n; i++){
    if (c[i] > 1){
      d.push_back(c[i]);
    }
  }
  int m = d.size();
  if (m > n / 2){
    cout << "NO" << endl;
    return 0;
  }
  vector<vector<bool>> dp1(1 << m, vector<bool>(cnt[1] + 1, false));
  vector<vector<vector<bool>>> dp2(1 << m, vector<vector<bool>>(cnt[1] + 1, vector<bool>(n + 1, false)));
  for (int i = 0; i < m; i++){
    if (d[i] - 1 <= cnt[1]){
      dp1[1 << i][d[i] - 1] = true;
    }
  }
  vector<int> mx(1 << m, 0);
  vector<int> id(1 << m, 0);
  for (int i = 1; i < (1 << m); i++){
    for (int j = 0; j < m; j++){
      if (i >> j & 1){
        if (d[j] > mx[i]){
          mx[i] = d[j];
          id[i] = j;
        }
      }
    }
  }
  for (int i = 1; i < (1 << m); i++){
    if (__builtin_popcount(i) > 1){
      for (int j = 2; j <= cnt[1]; j++){
        for (int k = 0; k < mx[i]; k++){
          if (dp2[i - (1 << id[i])][j][k]){
            int add = mx[i] - k - 1;
            if (j + add <= cnt[1]){
              dp1[i][j + add] = true;
            }
          }
        }
        if (dp1[i - (1 << id[i])][j]){
          int add = mx[i] - mx[i - (1 << id[i])] - 1;
          if (add > 0 && j + add <= cnt[1]){
            dp1[i][j + add] = true;
          }
        }
      }
      for (int j = i; j > 0; j = (j - 1) & i){
        if (j != i){
          for (int k = 0; k < cnt[1]; k++){
            if (dp1[j][k]){
              if (mx[j] + mx[i - j] <= n){
                for (int l = 0; l <= cnt[1] - k; l++){
                  if (dp1[i - j][l]){
                    dp2[i][k + l][mx[j] + mx[i - j]] = true;
                  }
                }
              }
              for (int l = 0; l <= cnt[1] - k; l++){
                for (int o = 0; o <= n - mx[j]; o++){
                  if (dp2[i - j][l][o]){
                    dp2[i][k + l][mx[j] + o] = true;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (dp1[(1 << m) - 1][cnt[1]]){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}