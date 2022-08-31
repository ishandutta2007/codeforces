#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      vector<vector<int>> ans(n, vector<int>(m, 0));
      for (int j = 0; j < n * a; j++){
        ans[j % n][j / b] = 1;
      }
      for (int j = 0; j < n; j++){
        for (int k = 0; k < m; k++){
          cout << ans[j][k];
        }
        cout << endl;
      }
    }
  }
}