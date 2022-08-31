#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> ans(n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int x = i * n + j + 1;
      if (i % 2 == 0){
        ans[j].push_back(x);
      } else {
        ans[n - 1 - j].push_back(x);
      }
    }
  }
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