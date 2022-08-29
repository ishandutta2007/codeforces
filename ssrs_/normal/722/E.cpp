#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b & 1){
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
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(long long n){
	if (n < mf.size()){
		return mf[n];
	} else {
		for (int i = mf.size(); i <= n; i++){
		  long long next = mf.back() * i % MOD;
		  mf.push_back(next);
		  mfi.push_back(modinv(next));
		}
		return mf[n];
	}
}
long long finv(int n){
  if (n < mfi.size()){
    return mfi[n];
  } else {
    return modinv(modfact(n));
  }
}
long long modbinom(long long n, long long r){
  return modfact(n) * finv(r) % MOD * finv(n - r) % MOD;
}
int main(){
  int N, M, K, S;
  cin >> N >> M >> K >> S;
  vector<pair<int, int>> pos(K + 2);
  for (int i = 0; i < K; i++){
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    pos[i] = make_pair(r, c);
  }
  pos[K] = make_pair(0, 0);
  pos[K + 1] = make_pair(N - 1, M - 1);
  sort(pos.begin(), pos.end());
  vector<array<long long, 23>> dp(K + 2);
  dp[0][0] = 1;
  for (int i = 1; i <= K + 1; i++){
    for (int j = 0; j < 23; j++){
      for (int k = 0; k < i; k++){
        int y = pos[i].first - pos[k].first;
        int x = pos[i].second - pos[k].second;
        if (y >= 0 && x >= 0 && dp[k][j] != 0){
          long long c = modbinom(y + x, x);
          dp[i][min(j + 1, 22)] += dp[k][j] * c;
          dp[i][min(j + 1, 22)] %= MOD;
        }
      }
    }
    int u = min(i, 22);
    for (int j = 1; j < u; j++){
      dp[i][j] = (dp[i][j] - dp[i][j + 1] + MOD) % MOD;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 23; i++){
    ans += dp[K + 1][i] * S;
    if (i != 0){
      S = (S + 1) / 2;
    }
  }
  ans %= MOD;
  ans *= modinv(modbinom(N + M - 2, N - 1));
  ans %= MOD;
  cout << ans << endl;
}