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
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(100001, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  vector<int> mcnt = cnt;
  for (int i = 1; i <= 100000; i++){
    for (int j = i * 2; j <= 100000; j += i){
      mcnt[i] += mcnt[j];
    }
  }
  vector<long long> c(100001, 0);
  for (int i = 1; i <= 100000; i++){
    c[i] = (modpow(2, mcnt[i]) + MOD - 1) % MOD;
  }
  for (int i = 100000; i >= 1; i--){
    for (int j = i * 2; j <= 100000; j += i){
      c[i] = (c[i] + MOD - c[j]) % MOD;
    }
  }
  cout << c[1] << endl;
}