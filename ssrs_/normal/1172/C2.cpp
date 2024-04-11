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
map<long long, long long> mp;
long long modinv(long long a){
  if (mp.count(a)){
    return mp[a];
  } else {
    mp[a] = modpow(a, MOD - 2);
    return mp[a];
  }
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
  
  vector<long long> dp2(m + 1);
  dp2[0] = 1;
  for (int i = 0; i < m; i++){
    if (dp2[i] != 0){
      dp2[i + 1] += dp2[i] * (sumB - i) % MOD * modinv(sumA + sumB - i) % MOD;
      dp2[i + 1] -= dp2[i] * modinv(sumA + sumB - i) % MOD;
      dp2[i + 1] += MOD;
      dp2[i + 1] %= MOD;
    }
  }
  /*
  for (int i = 0; i <= m; i++){
    for (int j = 0; j <= m; j++){
      cout << dp2[i] * modinv(dp[i][0]) % MOD << ' ';
    }
    cout << endl;
  }
  cout << endl;
  */
  long long ans1 = 0;
  for (int i = 0; i <= m; i++){
    ans1 += dp2[i] * modinv(dp[i][0]) % MOD * dp[i][m - i] % MOD;
  }
  ans1 %= MOD;
  vector<long long> dp3(m + 1);
  dp3[0] = 1;
  for (int i = 0; i < m; i++){
    if (dp3[i] != 0){
      dp3[i + 1] += dp3[i] * (sumA + i) % MOD * modinv(sumA + i + sumB) % MOD;
      dp3[i + 1] += dp3[i] * modinv(sumA + i + sumB) % MOD;
      dp3[i + 1] %= MOD;
    }
  }
  /*
  for (int i = 0; i <= m; i++){
    for (int j = 0; j <= m; j++){
      cout << dp3[j] * modinv(dp[0][j]) % MOD << ' ';
    }
    cout << endl;
  }
  cout << endl;
  */
  long long ans2 = 0;
  for (int i = 0; i <= m; i++){
    ans2 += dp3[i] * modinv(dp[0][i]) % MOD * dp[m - i][i] % MOD;
  }
  ans2 %= MOD;
  for (int i = 0; i < n; i++){
    if (a[i] == 0){
      cout << ans1 * w[i] % MOD << endl;
    } else {
      cout << ans2 * w[i] % MOD << endl;
    }
  }
}