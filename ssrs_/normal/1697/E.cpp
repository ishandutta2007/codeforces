#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
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
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  vector<vector<int>> d(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
  }
  vector<int> mn(n, INF);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != j){
        mn[i] = min(mn[i], d[i][j]);
      }
    }
  }
  vector<bool> ok(n, true);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != j && d[i][j] == mn[i]){
        if (d[i][j] != mn[j]){
          ok[i] = false;;
        }
      }
    }
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      if (d[i][j] == mn[i] && d[i][j] == mn[j]){
        E[i].push_back(j);
        E[j].push_back(i);
      }
    }
  }
  vector<bool> used(n, false);
  vector<pair<int, bool>> C;
  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      queue<int> Q;
      Q.push(i);
      int cntV = 0, cntE = 0;
      bool ok2 = true;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        cntV++;
        if (!ok[v]){
          ok2 = false;
        }
        for (int w : E[v]){
          cntE++;
          if (!used[w]){
            used[w] = true;
            Q.push(w);
          }
        }
      }
      if (cntE == cntV * (cntV - 1) && cntV > 1 && ok2){
        C.push_back(make_pair(cntV, true));
      } else {
        C.push_back(make_pair(cntV, false));
      }
    }
  }
  int cnt = C.size();
  vector<vector<long long>> dp(cnt + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < cnt; i++){
    for (int j = 0; j <= n; j++){
      if (dp[i][j] > 0){
        dp[i + 1][j + C[i].first] += dp[i][j];
        dp[i + 1][j + C[i].first] %= MOD;
        if (C[i].second){
          dp[i + 1][j + 1] += dp[i][j];
          dp[i + 1][j + 1] %= MOD;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++){
    ans += dp[cnt][i] * modfact(n) % MOD * modfactinv(n - i) % MOD;
  }
  ans %= MOD;
  cout << ans << endl;
}