#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        int cnt = 0;
        if (j == 0 || j == n - 1){
          cnt++;
        }
        if (k == 0 || k == m - 1){
          cnt++;
        }
        if (cnt == 0){
          b[j][k] = 4;
        }
        if (cnt == 1){
          b[j][k] = 3;
        }
        if (cnt == 2){
          b[j][k] = 2;
        }
      }
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (a[j][k] > b[j][k]){
          ok = false;
        }
      }
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int j = 0; j < n; j++){
        for (int k = 0; k < m; k++){
          cout << b[j][k];
          if (k < m - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}