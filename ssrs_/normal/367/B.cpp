#include <bits/stdc++.h>
using namespace std;
const long long BASE = 10000000;
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
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  vector<long long> a2(n);
  for (int i = 0; i < n; i++){
    a2[i] = modpow(BASE, a[i]);
  }
  long long sum = 0;
  for (int i = 0; i < m; i++){
    sum += modpow(BASE, b[i]);
  }
  sum %= MOD;
  vector<long long> S(n + p, 0);
  for (int i = p; i < n + p; i++){
    S[i] = S[i - p] + a2[i - p];
    S[i] %= MOD;
  }
  vector<int> ans;
  for (int i = 0; i + (long long) m * p < n + p; i++){
    long long hash = (S[i + m * p] - S[i] + MOD) % MOD;
    if (hash == sum){
      ans.push_back(i);
    }
  }
  int cnt = ans.size();
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++){
    cout << ans[i] + 1;
    if (i < cnt - 1){
      cout << ' ';
    }
  }
  cout << endl;
}