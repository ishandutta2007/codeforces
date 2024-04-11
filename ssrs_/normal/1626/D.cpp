#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
struct dual_sparse_table{
  int N, LOG;
  vector<vector<int>> ST;
  dual_sparse_table(int N): N(N){
    LOG = 32 - __builtin_clz(N);
    ST = vector<vector<int>>(LOG, vector<int>(N, INF));
  }
  void range_chmin(int L, int R, int x){
    int d = 31 - __builtin_clz(R - L);
    ST[d][L] = min(ST[d][L], x);
    ST[d][R - (1 << d)] = min(ST[d][R - (1 << d)], x);
  }
  vector<int> get(){
    for (int i = LOG - 2; i >= 0; i--){
      for (int j = 0; j < N - (1 << i); j++){
        ST[i][j] = min(ST[i][j], ST[i + 1][j]);
        ST[i][j + (1 << i)] = min(ST[i][j + (1 << i)], ST[i + 1][j]);
      }
    }
    return ST[0];
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    vector<int> S(n + 1, 0);
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + cnt[j];
    }
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int j = 0; j < 3; j++){
      dual_sparse_table ST(n + 1);
      for (int k = 0; k <= n; k++){
        for (int l = 0; l < 20; l++){
          int mn;
          if (l == 0){
            mn = -1;
          } else {
            mn = 1 << (l - 1);
          }
          int mx = 1 << l;
          int L = upper_bound(S.begin(), S.end(), S[k] + mn) - S.begin();
          int R = upper_bound(S.begin(), S.end(), S[k] + mx) - S.begin();
          if (L < R){
            ST.range_chmin(L, R, dp[k] + S[k] + (1 << l));
          }
        }
      }
      vector<int> mn = ST.get();
      for (int k = 0; k <= n; k++){
        dp[k] = mn[k] - S[k];
      }
    }
    cout << dp[n] << endl;
  }
}