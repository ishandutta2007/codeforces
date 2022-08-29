#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 1){
      cout << 1 << endl;
    } else if (n == 2){
      cout << -1 << endl;
    } else {
      vector<vector<int>> ans(n, vector<int>(n));
      int x = 0;
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          if ((j + k) % 2 == 0){
            ans[j][k] = x;
            x++;
          }
        }
      }
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          if ((j + k) % 2 == 1){
            ans[j][k] = x;
            x++;
          }
        }
      }
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          cout << ans[j][k] + 1;
          if (k < n - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}