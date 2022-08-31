#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<vector<int>> ans(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++){
    ans[i][i] = p[i];
    int x = i, y = i;
    for (int j = 0; j < p[i] - 1; j++){
      if (y == 0){
        x++;
      } else if (ans[x][y - 1] != -1){
        x++;
      } else {
        y--;
      }
      ans[x][y] = p[i];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      cout << ans[i][j];
      if (j < i){
        cout << ' ';
      }
    }
    cout << endl;
  }
}