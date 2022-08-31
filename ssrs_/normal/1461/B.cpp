#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> c[j][k];
      }
    }
    vector<vector<int>> S(n, vector<int>(m + 1));
    for (int j = 0; j < n; j++){
      S[j][0] = 0;
      for (int k = 0; k < m; k++){
        S[j][k + 1] = S[j][k];
        if (c[j][k] == '*'){
          S[j][k + 1]++;
        }
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        for (int l = 0; l <= n - j; l++){
          bool ok = true;
          if (l == n - j){
            ok = false;
          }
          if (k - l < 0){
            ok = false;
          }
          if (k + l >= m){
            ok = false;
          }
          if (ok){
            if (S[j + l][k + l + 1] - S[j + l][k - l] != l * 2 + 1){
              ok = false;
            }
          }
          if (!ok){
            ans += l;
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }
}