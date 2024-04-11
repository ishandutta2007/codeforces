#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long modpow(long long a, long long b){
	a %= MOD;
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  int sumA = 0, sumB = 0;
  for (int i = 0; i < n; i++){
    if (a[i] == 1){
      sumA += w[i];
    } else {
      sumB += w[i];
    }
  }
  //dp: probability
  vector<vector<long long>> dp(m + 1, vector<long long>(m + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      if (dp[i][j] != 0){
        dp[i][j + 1] += dp[i][j] * (sumA + j) % MOD * modinv(sumA + j + sumB - i) % MOD;
        dp[i + 1][j] += dp[i][j] * (sumB - i) % MOD * modinv(sumA + j + sumB - i) % MOD;
      }
    }
  }
  /*
  for (int i = 0; i <= m; i++){
    for (int j = 0; j <= m; j++){
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  */
  for (int i = 0; i < n; i++){
    if (a[i] == 0){
      vector<vector<long long>> dp2(m + 1, vector<long long>(m + 1, 0));
      dp2[0][0] = w[i];
      for (int j = 0; j < m; j++){
        for (int k = 0; k < m; k++){
          if (dp[j][k] != 0 && dp2[j][k] != 0){
            dp2[j][k + 1] += dp2[j][k] * (sumA + k) % MOD * modinv(sumA + k + sumB - j) % MOD;
            dp2[j][k + 1] %= MOD;
            dp2[j + 1][k] += dp2[j][k] * (sumB - j) % MOD * modinv(sumA + k + sumB - j) % MOD;
            dp2[j + 1][k] -= dp2[j][k] * modinv(sumA + k + sumB - j) % MOD;
            dp2[j + 1][k] += MOD;
            dp2[j + 1][k] %= MOD;
          }
        }
      }
      /*
      for (int j = 0; j <= m; j++){
        for (int k = 0; k <= m; k++){
          cout << dp2[j][k] * modinv(dp[j][k]) % MOD << ' ';
        }
        cout << endl;
      }
      cout << endl;
      */
      long long ans = 0;
      for (int j = 0; j <= m; j++){
        ans += dp2[j][m - j] % MOD;
      }
      cout << ans % MOD << endl;
    } else {
      vector<vector<long long>> dp2(m + 1, vector<long long>(m + 1, 0));
      dp2[0][0] = w[i];
      for (int j = 0; j < m; j++){
        for (int k = 0; k < m; k++){
          if (dp[j][k] != 0 && dp2[j][k] != 0){
            dp2[j + 1][k] += dp2[j][k] * (sumB - j) % MOD * modinv(sumA + k + sumB - j) % MOD;
            dp2[j + 1][k] %= MOD;
            dp2[j][k + 1] += dp2[j][k] * (sumA + k) % MOD * modinv(sumA + k + sumB - j) % MOD;
            dp2[j][k + 1] += dp2[j][k] * modinv(sumA + k + sumB - j) % MOD;
            dp2[j][k + 1] %= MOD;
          }
        }
      }
      /*
      for (int j = 0; j <= m; j++){
        for (int k = 0; k <= m; k++){
          cout << dp2[j][k] * modinv(dp[j][k]) % MOD << ' ';
        }
        cout << endl;
      }
      cout << endl;
      */
      long long ans = 0;
      for (int j = 0; j <= m; j++){
        ans += dp2[j][m - j] % MOD;
      }
      cout << ans % MOD << endl;
    }
  }
}