#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
vector<int> mp(string s){
  int N = s.size();
  vector<int> A(N + 1);
  A[0] = -1;
  int j = -1;
  for (int i = 0; i < N; i++){
    while (j >= 0){
      if (s[i] == s[j]){
        break;
      }
      j = A[j];
    }
    j++;
    A[i + 1] = j;
  }
  return A;
}
int main(){
  string s;
  cin >> s;
  string t;
  cin >> t;
  int N = s.size();
  int M = t.size();
  if (M > N){
    cout << 0 << endl;
  } else {
    vector<vector<int>> next(M + 1, vector<int>(26, 0));
    for (int i = 1; i <= M; i++){
      string t2 = t.substr(0, i - 1) + '$' + t;
      vector<int> a = mp(t2);
      int id = t[i - 1] - 'a';
      for (int j = i - 1; j <= M; j++){
        if (a[i + j] == i - 1){
          next[j][id] = i;
        }
      }
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j <= M; j++){
        if (dp[i][j] != -INF){
          for (int k = 0; k < 26; k++){
            if (s[i] == '?' || s[i] == 'a' + k){
              int j2 = next[j][k];
              if (j2 == M){
                dp[i + 1][j2] = max(dp[i + 1][j2], dp[i][j] + 1);
              } else {
                dp[i + 1][j2] = max(dp[i + 1][j2], dp[i][j]);
              }
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= M; i++){
      ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
  }
}