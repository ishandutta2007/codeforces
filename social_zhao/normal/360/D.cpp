#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m, P, g, phi, f[N], a[N], b[N];
map<int, int> vis;

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

namespace BSGS {
	int fac[N], tot;
	
	void GetFact() {
		int tmp = phi;
		for(int i = 2; i * i <= tmp; i++) {
			if(tmp % i == 0) fac[++tot] = i;
			while(tmp % i == 0) tmp /= i;
		}
		if(tmp > 1) fac[++tot] = tmp;
		sort(fac + 1, fac + 1 + tot);
	}
	
	int query(int x) {
		if(x == 1) return phi;
		int tmp = phi;
		for(int i = 1; i <= tot; i++) {
			while(tmp % fac[i] == 0 && qpow(x, tmp / fac[i]) == 1) 
				tmp /= fac[i];
		}
		return phi / tmp;
	} 
}
using namespace BSGS;

main() {
	n = get(), m = get(), P = get();
	phi = P - 1, GetFact(); 
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= m; i++) b[i] = get(), g = gcd(g, b[i]);
	for(int i = 1; i <= n; i++) a[i] = gcd(phi, g * query(a[i])), vis[a[i]] = 1;
	tot = 0;
	for(int i = 1; i * i <= phi; i++) {
		if(phi % i == 0) {
			fac[++tot] = i;
			if(i * i != phi) fac[++tot] = phi / i;
		}
	}
	sort(fac + 1, fac + 1 + tot);
	int ans = 0;
	for(int i = 1; i <= tot; i++) {
		for(int j = 1; j <= i; j++) if(fac[i] % fac[j] == 0) f[i] += vis[fac[j]];
		f[i] = -(f[i] == 0) + 1;
		for(int j = 1; j < i; j++) if(fac[i] % fac[j] == 0) f[i] -= f[j];
		ans += f[i] * (phi / fac[i]);
	}
	cout << ans;
	return 0;
}