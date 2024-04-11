#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    if (n == 1 && m == 1){
      if (a[0][0] == 0){
        cout << "Jeel" << endl;
      } else {
        cout << "Ashish" << endl;
      }
    } else {
      vector<int> X(n + m - 2, 0);
      for (int j = 0; j < n; j++){
        for (int k = 0; k < m; k++){
          int s = j + k;
          if (s == n + m - 2){
            s--;
          }
          X[s] ^= a[j][k];
        }
      }
      bool ok = false;
      for (int j = 0; j < n + m - 2; j++){
        if (X[j] != 0){
          ok = true;
        }
      }
      if (ok){
        cout << "Ashish" << endl;
      } else {
        cout << "Jeel" << endl;
      }
    }
  }
}