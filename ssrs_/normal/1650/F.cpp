#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> e(m), t(m), p(m);
    for (int j = 0; j < m; j++){
      cin >> e[j] >> t[j] >> p[j];
      e[j]--;
    }
    vector<vector<int>> id(n);
    for (int j = 0; j < m; j++){
      id[e[j]].push_back(j);
    }
    vector<int> ans;
    long long sum = 0;
    bool ok = true;
    for (int j = 0; j < n; j++){
      int cnt = id[j].size();
      vector<vector<int>> dp(cnt + 1, vector<int>(101, INF));
      dp[0][0] = 0;
      for (int k = 0; k < cnt; k++){
        dp[k + 1] = dp[k];
        for (int l = 0; l <= 100; l++){
          int l2 = min(l + p[id[j][k]], 100);
          dp[k + 1][l2] = min(dp[k + 1][l2], dp[k][l] + t[id[j][k]]);
        }
      }
      sum += dp[cnt][100];
      if (sum > a[j]){
        ok = false;
        break;
      }
      int cp = 100;
      for (int k = cnt - 1; k >= 0; k--){
        if (cp >= p[id[j][k]]){
          for (int l = 0; l <= 100; l++){
            int l2 = min(l + p[id[j][k]], 100);
            if (l2 == cp && dp[k][l] + t[id[j][k]] == dp[k + 1][l2]){
              cp = l;
              ans.push_back(id[j][k]);
              break;
            }
          }
        }
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      int k = ans.size();
      cout << k << endl;
      for (int j = 0; j < k; j++){
        cout << ans[j] + 1;
        if (j < k - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}