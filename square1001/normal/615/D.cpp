#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int binpow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int n, x, c[200009];
int main() {
	scanf("%d", &n);
	int mul = 1;
	for(int i = 0; i < n; i++) scanf("%d", &x), c[x]++, mul = 1LL * mul * x % mod;
	int ret = 1, cnt = 0;
	for(int i = 1; i <= 200000; i++) {
		if(c[i] % 2 == 1 && cnt == 0) ret = 1LL * ret * (c[i] + 1) / 2 % (mod - 1), cnt++;
		else ret = 1LL * ret * (c[i] + 1) % (mod - 1);
	}
	if(cnt >= 1) cout << binpow(mul, ret) << endl;
	else {
		mul = 1;
		for(int i = 1; i <= 200000; i++) {
			for(int j = 0; j < c[i] / 2; j++) mul = 1LL * mul * i % mod;
		}
		cout << binpow(mul, ret) << endl;
	}
	return 0;
}