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
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    rb--;
    cb--;
    rd--;
    cd--;
    vector<bool> C;
    int dr = 1, dc = 1;
    if (rb == n - 1){
      dr = -1;
    }
    if (cb == m - 1){
      dc = -1;
    }
    int rb2 = rb, cb2 = cb, dr2 = dr, dc2 = dc;
    while (true){
      if (rb2 == rd || cb2 == cd){
        C.push_back(true);
      } else {
        C.push_back(false);
      }
      rb2 += dr2;
      cb2 += dc2;
      if (rb2 == n - 1){
        dr2 = -1;
      }
      if (rb2 == 0){
        dr2 = 1;
      }
      if (cb2 == m - 1){
        dc2 = -1;
      }
      if (cb2 == 0){
        dc2 = 1;
      }
      if (rb2 == rb && cb2 == cb && dr2 == dr && dc2 == dc){
        break;
      }
    }
    int cnt = C.size();
    long long P = p * modinv(100) % MOD;
    long long P2 = 1;
    long long S = 0;
    for (int j = 0; j < cnt; j++){
      if (C[j]){
        S += P2 * P % MOD * j % MOD;
        P2 *= MOD + 1 - P;
        P2 %= MOD;
      }
    }
    S %= MOD;
    cout << (S + P2 * cnt % MOD) * modinv(MOD + 1 - P2) % MOD << endl;
  }
}