#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000;
int MAX = 10000;
int count_substring(string s, string t){
  int N = s.size();
  int M = t.size();
  if (N < M){
    return 0;
  } else {
    int ans = 0;
    for (int i = 0; i <= N - M; i++){
      if (s.substr(i, M) == t){
        ans++;
      }
    }
    return ans;
  }
}
int main(){
  int n;
  long long l;
  cin >> n >> l;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  a.push_back(0);
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  s.push_back("");
  vector<vector<int>> d(n + 1, vector<int>(n));
  vector<vector<int>> w(n + 1, vector<int>(n));
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < n; j++){
      int N = s[i].size();
      int M = s[j].size();
      d[i][j] = M;
      for (int k = min(N, M) - 1; k >= 1; k--){
        if (s[i].substr(N - k, k) == s[j].substr(0, k)){
          d[i][j] = M - k;
          break;
        }
      }
      string S = s[i] + s[j].substr(s[j].size() - d[i][j], d[i][j]);
      for (int k = 0; k < n; k++){
        int cnt1 = count_substring(S, s[k]);
        int cnt2 = count_substring(s[i], s[k]);
        w[i][j] += a[k] * (cnt1 - cnt2);
      }
    }
  }
  vector<vector<long long>> dp(MAX + 1, vector<long long>(n + 1, -INF));
  dp[0][n] = 0;
  for (int i = 0; i < MAX; i++){
    for (int j = 0; j <= n; j++){
      for (int k = 0; k < n; k++){
        if (i + d[j][k] <= MAX && dp[i][j] != -INF){
          dp[i + d[j][k]][k] = max(dp[i + d[j][k]][k], dp[i][j] + w[j][k]);
          
        }
      }
    }
  }
  if (l <= MAX){
    long long ans = 0;
    for (int i = 0; i <= l; i++){
      for (int j = 0; j < n; j++){
        ans = max(ans, dp[i][j]);
      }
    }
    cout << ans << endl;
  } else {
    long long ans = 0;
    for (int i = 0; i < n; i++){
      for (int j = 1; j <= 200; j++){
        long long d = 0;
        for (int k = 0; k <= 400; k++){
          d = max(d, dp[MAX - k][i] - dp[MAX - j - k][i]);
        }
        if (d > 0 && d < 100000000000){
          bool ok = true;
          for (int k = 0; k <= 400; k++){
            if (dp[MAX - k][i] - dp[MAX - j - k][i] != d && dp[MAX - k][i] != -INF && dp[MAX - j - k][i] != -INF){
              ok = false;
              break;
            }
          }
          if (ok){
            for (int k = MAX - 1000; k <= MAX; k++){
              if (dp[k][i] != -INF){
                ans = max(ans, dp[k][i] + (l - k) / j * d);
              }
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}