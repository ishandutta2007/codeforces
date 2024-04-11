#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    if (n < k * 2 - 1){
      cout << -1 << endl;
    } else {
      vector<vector<char>> ans(n, vector<char>(n, '.'));
      for (int j = 0; j < k; j++){
        ans[j * 2][j * 2] = 'R';
      }
      for (int j = 0; j < n; j++){
        for (int l = 0; l < n; l++){
          cout << ans[j][l];
        }
        cout << endl;
      }
    }
  }
}