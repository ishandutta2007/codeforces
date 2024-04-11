#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
int main(){
  vector<vector<vector<vector<long long>>>> dp(100, vector<vector<vector<long long>>>(12, vector<vector<long long>>(12, vector<long long>(12, 0))));
  dp[0][0][0][0] = 1;
  for (int i = 0; i < 99; i++){
    for (int j = 0; j < 12; j++){
      for (int k = 0; k < 12; k++){
        for (int l = 0; l < 12; l++){
          dp[i + 1][0][k][l] += dp[i][j][k][l];
          dp[i + 1][0][k][l] %= MOD;
          for (int m = 1; m < min(12 - k, i + 1); m++){
            if (m > j){
              if (l < 11){
                dp[i + 1][m][k + m][l + 1] += dp[i][j][k][l];
                dp[i + 1][m][k + m][l + 1] %= MOD;
              }
            } else {
              dp[i + 1][m][k + m][l] += dp[i][j][k][l];
              dp[i + 1][m][k + m][l] %= MOD;
            }
          }
        }
      }
    }
  }
  vector<vector<vector<long long>>> sum(100, vector<vector<long long>>(12, vector<long long>(12, 0)));
  for (int i = 0; i < 100; i++){
    for (int j = 0; j < 12; j++){
      for (int k = 0; k < 12; k++){
        for (int l = 0; l < 12; l++){
          sum[i][k][l] += dp[i][j][k][l];
          sum[i][k][l] %= MOD;
        }
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k, x;
    cin >> n >> k >> x;
    if (x > k){
      cout << 0 << endl;
    } else if (n < 100){
      cout << sum[n][k][x] << endl;
    } else {
      long long ans = 0;
      for (int j = 20; j < 40; j++){
        long long L = sum[j][k][x];
        for (int l = 20; l < 40; l++){
          if (j != l){
            L *= n - l;
            L %= MOD;
            L *= modinv(j - l + MOD);
            L %= MOD;
          }
        }
        ans += L;
      }
      cout << ans % MOD << endl;
    }
  }
}