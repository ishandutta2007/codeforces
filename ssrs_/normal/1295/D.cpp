#include <bits/stdc++.h>
using namespace std;
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
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    long long a, m;
    cin >> a >> m;
    cout << euler_phi(m / __gcd(a, m)) << endl;
  }
}