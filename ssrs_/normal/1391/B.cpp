#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> c[j][k];
      }
    }
    int ans = 0;
    for (int j = 0; j < n - 1; j++){
      if (c[j][m - 1] == 'R'){
        ans++;
      }
    }
    for (int j = 0; j < m - 1; j++){
      if (c[n - 1][j] == 'D'){
        ans++;
      }
    }
    cout << ans << endl;
  }
}