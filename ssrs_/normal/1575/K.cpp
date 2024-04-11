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
  int n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  int ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  if (ax == bx && ay == by){
    cout << modpow(k, (long long) n * m) << endl;
  } else {
    cout << modpow(k, (long long) n * m - (long long) r * c) << endl;
  }
}