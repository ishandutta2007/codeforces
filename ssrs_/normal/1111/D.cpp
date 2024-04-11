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
long long modfact(int n){
	for (int i = mf.size(); i <= n; i++){
		long long next = mf.back() * i % MOD;
		mf.push_back(next);
	}
	return mf[n];
}
int main(){
  string s;
  cin >> s;
  int N = s.size();
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    if (islower(s[i])){
      a[i] = s[i] - 'a';
    }
    if (isupper(s[i])){
      a[i] = s[i] - 'A' + 26;
    }
  }
  vector<int> cnt(52, 0);
  for (int i = 0; i < N; i++){
    cnt[a[i]]++;
  }
  long long M = modpow(modfact(N / 2), 2);
  for (int i = 0; i < 52; i++){
    M *= modinv(modfact(cnt[i]));
    M %= MOD;
  }
  vector<vector<long long>> dp(53, vector<long long>(N / 2 + 1, 0));
  dp[0][0] = M;
  for (int i = 0; i < 52; i++){
    for (int j = 0; j <= N / 2; j++){
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
    }
    if (cnt[i] > 0){
      for (int j = 0; j <= N / 2 - cnt[i]; j++){
        dp[i + 1][j + cnt[i]] += dp[i][j];
        dp[i + 1][j + cnt[i]] %= MOD;
      }
    }
  }
  vector<vector<long long>> ans(52, vector<long long>(52));
  for (int i = 0; i < 52; i++){
    for (int j = i + 1; j < 52; j++){
      vector<long long> dp2 = dp[52];
      for (int k = cnt[i]; k <= N / 2; k++){
        dp2[k] += MOD - dp2[k - cnt[i]];
        dp2[k] %= MOD;
      }
      for (int k = cnt[j]; k <= N / 2; k++){
        dp2[k] += MOD - dp2[k - cnt[j]];
        dp2[k] %= MOD;
      }
      ans[i][j] = dp2[N / 2];
      if (N / 2 >= cnt[i] + cnt[j]){
        ans[i][j] += dp2[N / 2 - cnt[i] - cnt[j]];
        ans[i][j] %= MOD;
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int X = a[x], Y = a[y];
    if (X == Y){
      cout << dp[52][N / 2] << "\n";
    } else {
      if (X > Y){
        swap(X, Y);
      }
      cout << ans[X][Y] << "\n";
    }
  }
}