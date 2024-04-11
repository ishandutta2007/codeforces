#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> c(n, vector<char>(m));
    for (int j = 0; j < n; j++){
      for (int l = 0; l < m; l++){
        cin >> c[j][l];
      }
    }
    vector<vector<char>> c2(n, vector<char>(m, '.'));
    for (int j = 0; j < n; j++){
      for (int l = 0; l < m; l++){
        if (c[j][l] == '*'){
          int mx = 0;
          while (true){
            int p = mx + 1;
            bool ok = false;
            if (j >= p && l >= p && l + p < m){
              if (c[j - p][l - p] == '*' && c[j - p][l + p] == '*'){
                ok = true;
              }
            }
            if (ok){
              mx = p;
            } else {
              break;
            }
          }
          if (mx >= k){
            c2[j][l] = '*';
            for (int o = 1; o <= mx; o++){
              c2[j - o][l - o] = '*';
              c2[j - o][l + o] = '*';
            }
          }
        }
      }
    }
    if (c == c2){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}