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
long long f2(vector<int> &S, vector<int> &T, int x, int p){
  if (S.empty() && T.empty()){
    return 1;
  }
  if (p == 0){
    return modpow(2, S.size() + T.size());
  }
  int N = S.size();
  vector<int> S0, S1;
  for (int i = 0; i < N; i++){
    if ((S[i] >> (p - 1) & 1) == 0){
      S0.push_back(S[i]);
    } else {
      S1.push_back(S[i] ^ (1 << (p - 1)));
    }
  }
  int M = T.size();
  vector<int> T0, T1;
  for (int i = 0; i < M; i++){
    if ((T[i] >> (p - 1) & 1) == 0){
      T0.push_back(T[i]);
    } else {
      T1.push_back(T[i] ^ (1 << (p - 1)));
    }
  }
  if ((x >> (p - 1) & 1) == 1){
    return f2(S0, T1, x ^ (1 << (p - 1)), p - 1) * f2(S1, T0, x ^ (1 << (p - 1)), p - 1) % MOD;
  } else {
    long long ans = 0;
    ans += modpow(2, N);
    ans += modpow(2, M);
    ans += f2(S0, T0, x, p - 1);
    ans += f2(S1, T1, x, p - 1);
    ans -= modpow(2, S0.size());
    ans -= modpow(2, S1.size());
    ans -= modpow(2, T0.size());
    ans -= modpow(2, T1.size());
    ans++;
    ans %= MOD;
    return ans;
  }
}
long long f1(vector<int> S, int x, int p){
  if (S.empty()){
    return 1;
  }
  if (p == 0){
    return modpow(2, S.size());
  }
  int N = S.size();
  vector<int> S0, S1;
  for (int i = 0; i < N; i++){
    if ((S[i] >> (p - 1) & 1) == 0){
      S0.push_back(S[i]);
    } else {
      S1.push_back(S[i] ^ (1 << (p - 1)));
    }
  }
  if ((x >> (p - 1) & 1) == 0){
    return (f1(S0, x, p - 1) + f1(S1, x, p - 1) + MOD - 1) % MOD;
  } else {
    return f2(S0, S1, x ^ (1 << (p - 1)), p - 1);
  }
}
int main(){
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = f1(a, x, 30);
  ans += MOD - 1;
  ans %= MOD;
  cout << ans << endl;
}