#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> b(n, vector<int>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cin >> b[j][k];
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if ((j + k) % 4 == 0){
          if (j + k < n){
            if (j % 2 == 0){
              ans ^= b[j][k];
              ans ^= b[j][n - 1 - k];
            }
          } else {
            if (j % 2 == 1){
              ans ^= b[j][k];
              ans ^= b[j][n - 1 - k];
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}