#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<long long> P(119);
  P[0] = 1;
  for (int i = 1; i < 119; i++){
    P[i] = P[i - 1] * 2 % MOD;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<int> cnt(60, 0);
    for (int j = 0; j < 60; j++){
      for (int k = 0; k < n; k++){
        if (x[k] >> j & 1){
          cnt[j]++;
        }
      }
    }
    vector<vector<int>> cnt2(60, vector<int>(60, 0));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 60; k++){
        if (x[j] >> k & 1){
          for (int l = 0; l < 60; l++){
            if (x[j] >> l & 1){
              cnt2[k][l]++;
            }
          }
        }
      }
    }
    long long ans = 0;
    for (int j = 0; j < 60; j++){
      for (int k = 0; k < 60; k++){
        long long a = n - cnt[j] - cnt[k] + cnt2[j][k];
        long long b = cnt[j] - cnt2[j][k];
        long long c = cnt[k] - cnt2[j][k];
        long long d = cnt2[j][k];
        long long cnt = (c + d) * (c + d) * n - (c + d) * c * (a + c);
        cnt %= MOD;
        ans += cnt * P[j + k] % MOD;
      }
    }
    cout << ans % MOD << endl;
  }
}