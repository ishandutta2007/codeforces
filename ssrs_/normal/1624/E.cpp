#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> s2(n);
    for (int j = 0; j < n; j++){
      cin >> s2[j];
    }
    string s;
    cin >> s;
    vector<tuple<int, int, int>> P2(100, make_tuple(-1, -1, -1));
    vector<tuple<int, int, int>> P3(1000, make_tuple(-1, -1, -1));
    for (int j = 0; j < n; j++){
      for (int k = 0; k <= m - 2; k++){
        int x = stoi(s2[j].substr(k, 2));
        P2[x] = make_tuple(k, k + 2, j);
      }
      for (int k = 0; k <= m - 3; k++){
        int x = stoi(s2[j].substr(k, 3));
        P3[x] = make_tuple(k, k + 3, j);
      }
    }
    vector<bool> dp(m + 1, false);
    vector<int> pr(m + 1, -1);
    dp[0] = true;
    for (int j = 0; j <= m; j++){
      if (dp[j]){
        if (j + 2 <= m){
          int x = stoi(s.substr(j, 2));
          if (P2[x] != make_tuple(-1, -1, -1)){
            dp[j + 2] = true;
            pr[j + 2] = j;
          }
        }
        if (j + 3 <= m){
          int x = stoi(s.substr(j, 3));
          if (P3[x] != make_tuple(-1, -1, -1)){
            dp[j + 3] = true;
            pr[j + 3] = j;
          }
        }
      }
    }
    if (!dp[m]){
      cout << -1 << "\n";
    } else {
      int p = m;
      vector<tuple<int, int, int>> ans;
      while (p != 0){
        int q = pr[p];
        if (q == p - 2){
          int x = stoi(s.substr(q, 2));
          ans.push_back(P2[x]);
        }
        if (q == p - 3){
          int x = stoi(s.substr(q, 3));
          ans.push_back(P3[x]);
        }
        p = q;
      }
      reverse(ans.begin(), ans.end());
      int k = ans.size();
      cout << k << "\n";
      for (int j = 0; j < k; j++){
        cout << get<0>(ans[j]) + 1 << ' ' << get<1>(ans[j]) << ' ' << get<2>(ans[j]) + 1 << "\n";
      }
    }
  }
}