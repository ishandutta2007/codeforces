#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
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
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<long long>> P(n, vector<long long>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      P[i][j] = a[i] * modinv(a[i] + a[j]) % MOD;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    vector<long long> dp(1 << n, 0);
    for (int j = 0; j < (1 << n); j++){
      if ((j >> i & 1) == 1){
        dp[j] = 1;
        for (int k = 0; k < n; k++){
          for (int l = 0; l < n; l++){
            if ((j >> k & 1) == 1 && (j >> l & 1) == 0){
              dp[j] *= P[l][k];
              dp[j] %= MOD;
            }
          }
        }
        for (int k = j; k >= 0; k = (k - 1) & j){
          if (k != j && (k >> i & 1) == 1){
            long long p = dp[k];
            for (int l = 0; l < n; l++){
              if ((k >> l & 1) == 0 && (j >> l & 1) == 1){
                for (int m = 0; m < n; m++){
                  if ((j >> m & 1) == 0){
                    p *= P[m][l];
                    p %= MOD;
                  }
                }
              }
            }
            dp[j] += MOD - p;
            dp[j] %= MOD;
          }
          if (k == 0){
            break;
          }
        }
      }
    }
    ans += dp[(1 << n) - 1];
  }
  ans %= MOD;
  cout << ans << endl;
}