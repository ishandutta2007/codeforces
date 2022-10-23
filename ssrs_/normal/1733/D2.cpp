#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x, y;
    cin >> n >> x >> y;
    string a;
    cin >> a;
    string b;
    cin >> b;
    vector<int> c(n);
    for (int j = 0;  j < n; j++){
      if (a[j] == b[j]){
        c[j] = 0;
      } else {
        c[j] = 1;
      }
    }
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (c[j] == 1){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    if (cnt % 2 == 1){
      cout << -1 << endl;
    } else {
      x = min(x, y * 2);
      if (cnt == 0){
        cout << 0 << endl;
      } else if (cnt == 2){
        if (p[1] - p[0] >= 2){
          cout << min((long long) y, (long long) x * (p[1] - p[0])) << endl;
        } else {
          cout << x << endl;
        }
      } else {
        vector<vector<long long>> dp(5, vector<long long>(cnt + 1, INF));
        dp[0][0] = 0;
        for (int j = 0; j < cnt; j++){
          for (int k = 0; k < 5; k++){
            if (j < cnt - 1){
              int k2 = k;
              if (k == 4){
                k2 = 1;
              }
              dp[k2][j + 2] = min(dp[k2][j + 2], dp[k][j] + (long long) x * (p[j + 1] - p[j]));
            }
            if (k != 3){
              int k2 = k + 1;
              if (k == 4){
                k2 = 2;
              }
              if (k == 0 && p[j + 1] == p[j] + 1){
                k2 = 4;
              }
              dp[k2][j + 1] = min(dp[k2][j + 1], dp[k][j] + y);
            }
            if (k != 0 && k != 4){
              dp[k - 1][j + 1] = min(dp[k - 1][j + 1], dp[k][j]);
            }
          }
        }
        cout << dp[0][cnt] << endl;
      }
    }
  }
}