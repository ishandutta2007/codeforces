#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (n % 3 != 0 && j % 3 == 0){
        p.push_back(j);
      }
      if (n % 3 == 0 && j % 3 == 1){
        p.push_back(j);
      }
    }
    for (int j : p){
      for (int k = 0; k < m; k++){
        c[j][k] = 'X';
      }
    }
    int cnt = p.size();
    for (int j = 0; j < cnt - 1; j++){
      bool ok = false;
      for (int k = 0; k < m; k++){
        if (c[p[j] + 1][k] == 'X'){
          c[p[j] + 2][k] = 'X';
          ok = true;
          break;
        }
        if (c[p[j] + 2][k] == 'X'){
          c[p[j] + 1][k] = 'X';
          ok = true;
          break;
        }
      }
      if (!ok){
        c[p[j] + 1][0] = 'X';
        c[p[j] + 2][0] = 'X';
      }
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cout << c[j][k];
      }
      cout << "\n";
    }
  }
}