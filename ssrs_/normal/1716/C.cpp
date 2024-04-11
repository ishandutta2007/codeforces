#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int m;
    cin >> m;
    vector<vector<int>> a(2, vector<int>(m));
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    a[0][0] = -1;
    vector<vector<int>> mx1(2, vector<int>(m + 1, -INF));
    vector<vector<int>> mx2(2, vector<int>(m + 1, -INF));
    for (int j = 0; j < 2; j++){
      for (int k = m - 1; k >= 0; k--){
        mx1[j][k] = max(mx1[j][k + 1], a[j][k] - k);
        mx2[j][k] = max(mx2[j][k + 1], a[j][k] + k);
      }
    }
    int ans = INF;
    int mx = 0;
    for (int j = 0; j < m; j++){
      if (j % 2 == 0){
        ans = min(ans, max({mx + m * 2 - 1, mx1[0][j] + m * 2 - j, mx2[1][j] - j + 1}));
        mx = max(mx, a[0][j] - j * 2 + 1);
        mx = max(mx, a[1][j] - j * 2);
      } else {
        ans = min(ans, max({mx + m * 2 - 1, mx1[1][j] + m * 2 - j, mx2[0][j] - j + 1}));
        mx = max(mx, a[1][j] - j * 2 + 1);
        mx = max(mx, a[0][j] - j * 2);
      }
    }
    cout << ans << endl;
  }
}