#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> R(n, vector<int>(m));
  vector<vector<int>> C(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      R[i][j] = i;
      C[i][j] = j;
    }
  }
  vector<vector<int>> ans(n, vector<int>(m, 0));
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int r;
      cin >> r;
      r--;
      for (int j = 0; j < m - 1; j++){
        swap(R[r][j], R[r][j + 1]);
        swap(C[r][j], C[r][j + 1]);
      }
    }
    if (t == 2){
      int c;
      cin >> c;
      c--;
      for (int j = 0; j < n - 1; j++){
        swap(R[j][c], R[j + 1][c]);
        swap(C[j][c], C[j + 1][c]);
      }
    }
    if (t == 3){
      int r, c, x;
      cin >> r >> c >> x;
      r--;
      c--;
      ans[R[r][c]][C[r][c]] = x;
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << ans[i][j];
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}