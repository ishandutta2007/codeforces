#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<char>> c(n, vector<char>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c[i][j];
    }
  }
  vector<vector<int>> count(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= n - k; j++){
      bool flg = true;
      for (int p = 0; p < k; p++){
        if (c[i][j + p] == '#'){
          flg = false;
        }
      }
      if (flg){
        for (int p = 0; p < k; p++){
          count[i][j + p]++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= n - k; j++){
      bool flg = true;
      for (int p = 0; p < k; p++){
        if (c[j + p][i] == '#'){
          flg = false;
        }
      }
      if (flg){
        for (int p = 0; p < k; p++){
          count[j + p][i]++;
        }
      }
    }
  }
  int M = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      M = max(M, count[i][j]);
    }
  }
  bool flg = false;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (!flg && count[i][j] == M){
        cout << i + 1 << ' ' << j + 1 << endl;
        flg = true;
      }
    }
  }
}