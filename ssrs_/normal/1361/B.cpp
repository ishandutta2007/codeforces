#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long modsub(long long a, long long b){
	a %= MOD;
	b %= MOD;
	if (a >= b){
		return (a - b) % MOD;
	} else {
		return MOD - (b - a) % MOD;
	}
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
bool powmult_million(long long a, long long b, long long c){
  //is pow(a,b) * c > 10^6?
  if (a == 1){
    return c > 1000000;
  } else {
    long long ans = c;
    for (int i = 0; i < b; i++){
      ans *= a;
      if (ans > 1000000){
        return true;
      }
    }
    return false;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long p;
    cin >> n >> p;
    vector<int> k(n);
    for (int j = 0; j < n; j++){
      cin >> k[j];
    }
    sort(k.begin(), k.end());
    reverse(k.begin(), k.end());
    long long A_sum = modpow(p, k[0]);
    long long B_sum = 0;
    bool big = false;
    long long diff = 1;
    for (int j = 1; j < n; j++){
      long long pow_diff = k[j - 1] - k[j];
      if (diff == 0){
        diff = 1;
        A_sum += modpow(p, k[j]);
      } else if (big){
        diff = 1;
        B_sum += modpow(p, k[j]);
      } else {
        B_sum += modpow(p, k[j]);
        if (powmult_million(p, pow_diff, diff)){
          big = true;
        } else {
          diff *= modpow(p, pow_diff);
          assert(diff <= 1000000);
          diff--;
        }
      }
    }
    cout << modsub(A_sum, B_sum) << "\n";
  }
}