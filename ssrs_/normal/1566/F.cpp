#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    vector<int> l(m), r(m);
    for (int j = 0; j < m; j++){
      cin >> l[j] >> r[j];
    }
    vector<bool> used(m, false);
    for (int j = 0; j < m; j++){
      int x = lower_bound(a.begin(), a.end(), l[j]) - a.begin();
      int y = upper_bound(a.begin(), a.end(), r[j]) - a.begin();
      if (x != y){
        used[j] = true;
      }
    }
    vector<vector<pair<int, int>>> P(n + 1);
    for (int j = 0; j < m; j++){
      if (!used[j]){
        int p = lower_bound(a.begin(), a.end(), l[j]) - a.begin();
        P[p].push_back(make_pair(l[j], r[j]));
      }
    }
    for (int j = 0; j <= n; j++){
      sort(P[j].begin(), P[j].end());
    }
    vector<int> cnt(n + 1);
    for (int j = 0; j <= n; j++){
      cnt[j] = P[j].size();
    }
    int ml = 0;
    for (int j = 0; j < cnt[0]; j++){
      ml = max(ml, a[0] - P[0][j].second);
    }
    vector<long long> dp(cnt[1] + 1);
    for (int j = 0; j <= cnt[1]; j++){
      int d = 0;
      if (j > 0){
        d = P[1][j - 1].first - a[0];
      }
      dp[j] = d + ml + min(d, ml);
    }
    for (int j = 1; j < n; j++){
      int rmn = a[j];
      long long mn1 = INF, mn2 = INF;
      for (int k = cnt[j]; k >= 0; k--){
        long long d = a[j] - rmn;
        mn1 = min(mn1, dp[k] + d);
        mn2 = min(mn2, dp[k] + d * 2);
        if (k > 0){
          rmn = min(rmn, P[j][k - 1].second);
        }
      }
      vector<long long> dp2(cnt[j + 1] + 1);
      for (int k = 0; k <= cnt[j + 1]; k++){
        long long d = 0;
        if (k > 0){
          d = P[j + 1][k - 1].first - a[j];
        }
        dp2[k] = min(mn1 + d * 2, mn2 + d);
      }
      swap(dp, dp2);
    }
    cout << dp.back() << endl;
  }
}