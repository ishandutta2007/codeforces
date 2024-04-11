#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long remove_square(long long a){
  for (long long  i = 2; i * i <= a; i++){
    if (a % (i * i) == 0){
      while (a % (i * i) == 0){
        a /= (i * i);
      }
    }
  }
  return a;
}
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
map<int, int> inv;
long long modinv(long long a){
  if (inv.count(a)){
    return inv[a];
  } else {
  	inv[a] = modpow(a, MOD - 2);
  	return inv[a];
  }
}
vector<long long> mf;
long long modfact(long long n){
	if (n < mf.size()){
		return mf[n];
	} else {
		if (mf.empty()) mf.push_back(1);
		long long res = mf.back();
		for (int i = mf.size(); i <= n; i++){
			res = res * i % MOD;
			mf.push_back(res);
		}
		return res;
	}
}
long long modbinom(long long n, long long r){
  if (n < 0 || r < 0 || r > n){
    return 0;
  }
	long long res;
	res = modfact(n);
	res = res * modinv(modfact(r)) % MOD;
	res = res * modinv(modfact(n - r)) % MOD ;
	return res;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i] = remove_square(a[i]);
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]]++;
  }
  vector<int> c;
  for (auto P : mp){
    c.push_back(P.second);
  }
  int m = c.size();
  vector<int> s(m + 1, 0);
  s[0] = 0;
  for (int i = 0; i < m; i++){
    s[i + 1] = s[i] + c[i];
  }
  vector<vector<long long>> dp(m + 1, vector<long long>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < m; i++){
    for (int j = 0; j <= s[i]; j++){
      //j
      for (int k = 1; k <= c[i]; k++){
        //kO[v
        for (int l = 0; l <= min(j, k); l++){
          //jl
          long long tmp = dp[i][j];
          //c[i]k
          tmp *= modbinom(c[i] - 1, k - 1);
          tmp %= MOD;
          //lI
          tmp *= modbinom(j, l);
          tmp %= MOD;
          //s[i]+1-jk-lI
          tmp *= modbinom(s[i] + 1 - j, k - l);
          tmp %= MOD;
          //j-l+c[i]-k
          int tmp2 = j - l + c[i] - k;
          dp[i + 1][tmp2] = (dp[i + 1][tmp2] + tmp) % MOD;
        }
      }
    }
  }
  long long ans = dp[m][0];
  for (int i = 0; i < m; i++){
    ans = ans * modfact(c[i]) % MOD;
  }
  cout << ans << endl;
}