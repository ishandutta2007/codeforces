#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<char>> c(n, vector<char>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c[i][j];
    }
  }
  int m;
  cin >> m;
  vector<int> p(m);
  for (int i = 0; i < m; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> d(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++){
    d[i][i] = 0;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (c[i][j] == '1'){
        d[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
  vector<int> dp(m, INF);
  vector<int> pr(m, -1);
  dp[0] = 0;
  for (int i = 0; i < m; i++){
    for (int j = i + 1; j < min(i + n, m); j++){
      if (d[p[i]][p[j]] == j - i){
        if (dp[j] > dp[i] + 1){
          dp[j] = dp[i] + 1;
          pr[j] = i;
        }
      }
    }
  }
  vector<int> v;
  v.push_back(m - 1);
  while (v.back() != 0){
    int next = pr[v.back()];
    v.push_back(next);
  }
  reverse(v.begin(), v.end());
  int k = dp[m - 1] + 1;
  cout << k << endl;
  for (int i = 0; i < k; i++){
    cout << p[v[i]] + 1;
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}