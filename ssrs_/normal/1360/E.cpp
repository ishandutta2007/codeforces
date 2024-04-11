#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<char>> c(n, vector<char>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cin >> c[j][k];
      }
    }
    bool ok = true;
    for (int j = 0; j < n - 1; j++){
      for (int k = 0; k < n - 1; k++){
        if (c[j][k] == '1' && c[j + 1][k] == '0' && c[j][k + 1] == '0'){
          ok = false;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}