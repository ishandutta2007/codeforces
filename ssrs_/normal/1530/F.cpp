#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int MOD = 31607;
int modpow(int a, int b){
	int ans = 1;
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
int modinv(int a){
	return modpow(a, MOD - 2);
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
      a[i][j] *= modinv(10000);
      a[i][j] %= MOD;
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++){
    vector<int> P(1 << n, 1);
    for (int j = 0; j < n; j++){
      vector<int> b = a[j];
      int M = 1;
      if (i % 2 == 1){
        M *= b[j];
        b[j] = 1;
      }
      if (i >= 2){
        if (b[n - 1 - j] != 0){
          M *= b[n - 1 - j];
          M %= MOD;
        }
        b[n - 1 - j] = 1;
      }
      vector<int> F(1 << n, M);
      for (int k = 0; k < n; k++){
        for (int l = 0; l < (1 << n); l++){
          if ((l >> k & 1) == 1){
            F[l] *= b[k];
            F[l] %= MOD;
          }
        }
      }
      for (int k = 0; k < (1 << n); k++){
        F[k] += MOD - F.back();
        if (F[k] >= MOD){
          F[k] %= MOD;
        }
      }
      for (int k = 0; k < (1 << n); k++){
        P[k] *= F[k];
        P[k] %= MOD;
      }
    }
    long long S = 0;
    for (int j = 0; j < (1 << n); j++){
      if (__builtin_parity(j) == 0){
        S += P[j];
      } else {
        S += MOD - P[j];
      }
    }
    S %= MOD;
    if (i == 0 || i == 3){
      ans += S;
    } else {
      ans += MOD - S;
    }
  }
  ans %= MOD;
  ans = (MOD + 1 - ans) % MOD;
  cout << ans << endl;
}