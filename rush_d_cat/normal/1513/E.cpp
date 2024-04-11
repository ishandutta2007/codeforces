#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


const int N = 300000 + 10;
const LL MOD = 1e9 + 7;

LL fac[N],inv[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL c(int x,int y){
	if(y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void init() {
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[i-1]*inv[i]%MOD;
	}
}

int main() {
	init();

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);

	LL s = 0;
	map<int, int> mp;
	for (int i = 0; i < n; i ++	) {
		cin >> a[i]; s += a[i];
		mp[a[i]] ++;
	}

	if (s % n) {
		cout << 0 << endl; return 0;
	}
	int x = 0, y = 0;
	for (int i = 0; i < n; i ++) {
		if (a[i] > s / n) x ++;
		if (a[i] < s / n) y ++;
	}
	LL X = fac[x], Y = fac[y];
	for (auto p: mp) {
		if (p.first > s / n) X = X * inv[p.second] % MOD;
		if (p.first < s / n) Y = Y * inv[p.second] % MOD;
	}



	LL ways1 = c(n, n - x - y);

	LL sum = 0;
	if (min(x, y) <= 1) {
		if (x == 0) {
			sum = fac[y];
		} else if (y == 0) {
			sum = fac[x]; 
		} else {
			sum += X * Y % MOD * (x - 1) % MOD;
			sum += X * Y % MOD * (y - 1) % MOD;
			sum += X * Y % MOD * 2 % MOD;
			sum %= MOD;
		} 
	} else {
		sum = X * Y % MOD * 2 % MOD;
	}
	LL ans = ways1 * sum % MOD;
	cout << ans << endl;
}