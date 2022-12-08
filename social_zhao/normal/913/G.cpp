#include<bits/stdc++.h>
#define int long long
#define lxl __int128
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const lxl lxl1 = 1;
lxl a;
int n;

lxl qpow(lxl x, int y) {
	lxl res = 1;
	while(y) res = res * ((y & 1)? x : 1), x = x * x, y >>= 1;
	return res;
}

lxl mpow(lxl x, int y, lxl P) {
	lxl res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void solve() {
	a = get();
	lxl lim = 1; n = 0;
	while(a / lim) lim *= 10, ++n;
	for(lxl m = 0, now = 1; m <= 100; m++, now = now * 10) {
		lxl pw2 = qpow(2, n + m), pw5 = qpow(5, n + m);
		if(pw2 > now) continue;
		lxl b = (pw2 - now * a % pw2) % pw2;
		if((now * a + b) % 5 == 0) b += pw2;
		if(b >= now) continue;
//		cerr << "m = " << (int)m << endl;
		lxl x = (a * now + b) / pw2 % pw5;
//		cerr << "Aek + b: " << (int)(a * now + b) << endl;
//		cerr << "x: " << (int)x << endl;
		int res = 0;
		for(int i = 1; i <= n + m; i++) {
			lxl phi = qpow(5, i - 1), pw5 = phi * 5; phi = phi * 4;
			if(i == 1) phi = 1; else phi /= 5;
			for(int j = 0; j <= 4; j++)
				if(mpow(2, res + j * phi, pw5) == x % pw5) {
					res += j * phi; break;
				}
		}
		cout << (int)(res + n + m) << endl;
		return;
	}
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}