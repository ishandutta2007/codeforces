#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    for (int j = 0; j < n; j++){
      cin >> S[j];
    }
    vector<vector<int>> c(n + m - 1);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (S[j][k] == '1'){
          c[k + j].push_back(k - j);
        }
      }
    }
    int ans = 0;
    for (int j = 0; j < 2; j++){
      vector<int> dp(n * m, INF);
      for (int k = j; k < n + m - 1; k += 2){
        sort(c[k].begin(), c[k].end(), greater<int>());
        for (int x : c[k]){
          *lower_bound(dp.begin(), dp.end(), x) = x;
        }
      }
      int lis = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
      ans += lis;
    }
    cout << ans << endl;
  }
}