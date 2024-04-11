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
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n){
	if (mf.size() > n){
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
long long modfactinv(int n){
	if (mfi.size() > n){
		return mfi[n];
	} else {
		return modinv(modfact(n));
	}
}
long long modbinom(int n, int k){
	if (n < 0 || k < 0 || k > n){
		return 0;
	} else {
		return modfact(n) * modfactinv(k) % MOD * modfactinv(n - k) % MOD;
	}
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> bfs;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<int> dp(n, 1);
  for (int v : bfs){
    for (int w : c[v]){
      dp[v] += dp[w];
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    long long sum = 0;
    for (int j : c[i]){
      sum += modbinom(dp[j], k);
    }
    sum += modbinom(n - dp[i], k);
    sum %= MOD;
    for (int j : c[i]){
      long long sum2 = modbinom(n - dp[j], k) + MOD - (sum - modbinom(dp[j], k));
      sum2 %= MOD;
      sum2 *= dp[j];
      sum2 %= MOD;
      sum2 *= n - dp[j];
      sum2 %= MOD;
      ans += sum2;
    }
    if (i > 0){
      sum = modbinom(dp[i], k) + MOD - (sum - modbinom(n - dp[i], k));
      sum %= MOD;
      sum *= n - dp[i];
      sum %= MOD;
      sum *= dp[i];
      sum %= MOD;
      ans += sum;
    }
  }
  for (int i = 0; i < n; i++){
    long long sum = modbinom(n, k);
    for (int j : c[i]){
      sum += MOD - modbinom(dp[j], k);
      sum %= MOD;
    }
    sum += MOD - modbinom(n - dp[i], k);
    sum %= MOD;
    ans += sum * n;
    ans %= MOD;
  }
  ans %= MOD;
  cout << ans << endl;
}