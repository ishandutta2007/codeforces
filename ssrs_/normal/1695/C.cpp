#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    vector<vector<int>> dp1(n, vector<int>(m, INF));
    vector<vector<int>> dp2(n, vector<int>(m, -INF));
    dp1[0][0] = a[0][0];
    dp2[0][0] = a[0][0];
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (j < n - 1){
          dp1[j + 1][k] = min(dp1[j + 1][k], dp1[j][k] + a[j + 1][k]);
          dp2[j + 1][k] = max(dp2[j + 1][k], dp2[j][k] + a[j + 1][k]);
        }
        if (k < m - 1){
          dp1[j][k + 1] = min(dp1[j][k + 1], dp1[j][k] + a[j][k + 1]);
          dp2[j][k + 1] = max(dp2[j][k + 1], dp2[j][k] + a[j][k + 1]);
        }
      }
    }
    if ((n + m - 1) % 2 == 0 && dp1[n - 1][m - 1] <= 0 && dp2[n - 1][m - 1] >= 0){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}