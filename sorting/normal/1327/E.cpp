#include <bits/stdc++.h>

using namespace std;

const long long kMod = 998244353;

long long fpow(long long base, long long exp){
	if(!exp)
		return 1;
	if(exp & 1)
		return base * fpow(base, exp ^ 1) % kMod;

	long long t = fpow(base, exp >> 1);
	return t * t % kMod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 1; i < n; ++i){
		long long ans = 0;
		if(i != n - 1)
			ans += ((n - i - 1) * 10 * 81) % kMod * fpow(10, n - i - 2) % kMod;
		ans %= kMod;
		ans += 2 * 10 * 9 * fpow(10, n - i - 1) % kMod;
		ans %= kMod;
		cout << ans << " ";
	}
	cout << "10\n";
}