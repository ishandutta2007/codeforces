#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<vector<string>> s2(2, vector<string>(n));
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < n; k++){
        for (int l = 0; l < m; l++){
          if ((j + k + l) % 2 == 0){
            s2[j][k] += 'R';
          } else {
            s2[j][k] += 'W';
          }
        }
      }
    }
    vector<bool> ok(2, true);
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < n; k++){
        for (int l = 0; l < m; l++){
          if (s[k][l] == 'R' && s2[j][k][l] == 'W'){
            ok[j] = false;
          }
          if (s[k][l] == 'W' && s2[j][k][l] == 'R'){
            ok[j] = false;
          }
        }
      }
    }
    if (!ok[0] && !ok[1]){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int id;
      for (int j = 0; j < 2; j++){
        if (ok[j]){
          id = j;
        }
      }
      for (int j = 0; j < n; j++){
        cout << s2[id][j] << endl;
      }
    }
  }
}