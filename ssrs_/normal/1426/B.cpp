#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> A(n, vector<vector<int>>(2, vector<int>(2)));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 2; k++){
        for (int l = 0; l < 2; l++){
          cin >> A[j][k][l];
        }
      }
    }
    bool ok = false;
    for (int j = 0; j < n; j++){
      if (A[j][0][1] == A[j][1][0]){
        ok = true;
      }
    }
    if (m % 2 != 0){
      ok = false;
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}