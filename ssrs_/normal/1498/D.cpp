#include <bits/stdc++.h>
using namespace std;
const int LOG = 17;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < n; i++){
    int t;
    long long x;
    int y;
    cin >> t >> x >> y;
    y++;
    if (t == 1){
      x = (x + 99999) / 100000;
      vector<int> imos(m + 1, 0);
      for (int j = 0; j <= m; j++){
        if (dp[i][j]){
          imos[j]++;
          long long j2 = j + x * y;
          if (j2 <= m){
            imos[j2]--;
          }
        }
      }
      for (int j = x; j <= m; j++){
        imos[j] += imos[j - x];
      }
      for (int j = 0; j <= m; j++){
        if (imos[j] > 0){
          dp[i + 1][j] = true;
        }
      }
    }
    if (t == 2){
      vector<int> next(m + 2, 0);
      for (int i = 0; i <= m; i++){
        next[i] = min((i * x + 99999) / 100000, (long long) m + 1);
      }
      vector<int> p(m + 2, 0);
      for (int j = 0; j <= m + 1; j++){
        p[j] = j;
      }
      for (int j = LOG - 1; j >= 0; j--){
        vector<int> p2(m + 2);
        for (int k = 0; k <= m + 1; k++){
          p2[k] = p[p[k]];
        }
        swap(p, p2);
        if ((y >> j & 1) == 1){
          vector<int> p3(m + 2, 0);
          for (int k = 0; k <= m + 1; k++){
            p3[k] = next[p[k]];
          }
          swap(p, p3);
        }
      }
      vector<int> imos(m + 2, 0);
      for (int j = 0; j <= m; j++){
        if (dp[i][j]){
          imos[j]++;
          imos[p[j]]--;
        }
      }
      for (int j = 0; j <= m; j++){
        imos[next[j]] += imos[j];
      }
      dp[i + 1][0] = true;
      for (int j = 1; j <= m; j++){
        if (imos[j] > 0){
          dp[i + 1][j] = true;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++){
    int ans = -1;
    for (int j = 1; j <= n; j++){
      if (dp[j][i]){
        ans = j;
        break;
      }
    }
    cout << ans;
    if (i < m){
      cout << ' ';
    }
  }
  cout << endl;
}