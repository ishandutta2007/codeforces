#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long euler_phi(long long x){
	long long ans = x;
	for (long long i = 2; i * i <= x; i++){
		if (x % i == 0){
			ans /= i;
			ans *= i - 1;
			while (x % i == 0){
				x /= i;
			}
		}
	}
	if (x > 1){
		ans /= x;
		ans *= x - 1;
	}
	return ans;
}
int main(){
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < (k + 1) / 2; i++){
    n = euler_phi(n);
    if (n == 1){
      break;
    }
  }
  cout << n % MOD << endl;
}