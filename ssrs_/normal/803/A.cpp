#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> ans(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (ans[i][j] == 0){
        if (i == j && k >= 1){
          ans[i][j] = 1;
          k--;
        }
        if (i != j && k >= 2){
          ans[i][j] = 1;
          ans[j][i] = 1;
          k -= 2;
        }
      }
    }
  }
  if (k > 0){
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        cout << ans[i][j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}