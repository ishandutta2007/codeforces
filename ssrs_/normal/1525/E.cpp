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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> d(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> d[i][j];
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; i++){
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      x[j] = d[j][i] - 1;
    }
    sort(x.begin(), x.end());
    long long p = 1;
    for (int j = 0; j < n; j++){
      p *= max(x[j] - j, 0);
      p %= MOD;
    }
    ans += p;
    ans %= MOD;
  }
  long long cnt = 1;
  for (int i = 1; i <= n; i++){
    cnt *= i;
    cnt %= MOD;
  }
  ans *= modinv(cnt);
  ans %= MOD;
  ans = MOD + m - ans;
  ans %= MOD;
  cout << ans << endl;
}